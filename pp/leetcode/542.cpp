#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Solution {
private :
	class Posi{
		public:
		int x,y;
		Posi(int x,int y){
			this->x=x;
			this->y=y;
		}
	};
	int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

	bool NotInMap(int x,int y,int m,int n){
		return !(x<m&&y<n&&x>=0&&y>=0);
	}
public:
	vector<vector<int> > updateMatrix(vector<vector<int>>& mat) {
	int m,n;
	m = mat.size();	
	n = mat[0].size();
	vector<vector<int>>ans(m,vector<int>(n,0x3f3f3f3f));
	vector<vector<int>>vis(m,vector<int>(n,0));
	queue<Posi> q;
	for(int x=0;x<m;x++){
		for(int y=0;y<n;y++){
			if(mat[x][y]==0){
				ans[x][y]=0;
				vis[x][y] = 1;
				bool flag=false;
				for(int k=0;k<4;k++){
					int nx = x + dir[k][0],ny = y + dir[k][1];
					if(NotInMap(nx,ny,m,n))continue;
					q.push(Posi(x,y));
					break;	
				}

			}
		}
	}

	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dir[k][0],ny = y + dir[k][1];
			if(NotInMap(nx,ny,m,n))continue;
			if(vis[nx][ny] == 1)continue;
			ans[nx][ny] = ans[x][y]+1;
			vis[nx][ny] = 1;
			q.push(Posi(nx,ny));
		} 
	}
	

		return ans;
    }
};

int main()
{

	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		vector<vector<int>> mat(m,vector<int>(n,0));
		for (int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		Solution ans;
		vector<vector<int> > a = ans.updateMatrix(mat);
		for (int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<a[i][j]<<' ';
			}cout<<endl;
		}

	}
	return 0;
}















/*
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Posi
{
	public :
		int x,y;
		Posi(int x,int y){
			this->x=x;
			this->y=y;
		}
};

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};



int main()
{
	int m,n;
	vector<vector<int>> input;
	vector<vector<int>> ans;
	vector<vector<int>> vis;
	while(scanf("%d%d",&m,&n)==2){
		vis.clear();
		input.clear();
		ans.clear();
		for(int i=0;i<m;i++){
			vector<int> temp_vec_0(n,0);
			vector<int> temp_vec_max(n,0x3f3f3f3f);
			input.push_back(temp_vec_0);
			ans.push_back(temp_vec_max);
			vis.push_back(temp_vec_0);
			for(int j=0;j<n;j++){
				scanf("%d",&input[i][j]);
				if(input[i][j] == 0 )ans[i][j] = 0;
			}
		}
		
		queue<Posi>q;

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				bool flag =false;
				for(int k=0;k<4;k++){
					int nx = i+dir[k][0],ny = j+dir[k][1];
					if(nx>=m||ny>=n||nx<0||ny<0)continue;
					if(input[nx][ny] == 1){
						flag = true;
						break;
					}
				}
				if(flag&&input[i][j]==0){//表示这里是边缘
					q.push(Posi(i,j));
					vis[i][j]=1;
				}
			}
		}
		while(!q.empty()){
			Posi p = q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int nx = p.x+dir[i][0];
				int ny = p.y+dir[i][1];			
				if(nx>=m||ny>=n||nx<0||ny<0)continue;
				if(vis[nx][ny] == 1||ans[nx][ny] == 0)continue;
				//ans[nx][ny] = min(ans[nx][ny],ans[p.x][p.y]+1);
				ans[nx][ny] = ans[p.x][p.y]+1;
				//if(ans[nx][ny] == ans[p.x][p.y]+1)q.push(Posi(nx,ny));
				q.push(Posi(nx,ny));
				vis[nx][ny] = 1;

			}
		}


		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ",ans[i][j]);

			}
			cout<<endl;
		}
		cout<<endl;
	}

	return 0;
}
*/

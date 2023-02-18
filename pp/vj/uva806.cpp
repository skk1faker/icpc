#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int maxx = 64+2;
const int maxx2 = maxx * maxx*3/4;
int treenode[maxx2];
int image_ori[maxx][maxx];
int * image[maxx];  //使用数组指针去返回二维数组

char ans_image[maxx][maxx];
struct Posi
{
    int x,y,length;
    Posi(int x,int y,int length):x(x),y(y),length(length){}
};      // 表示图像的位置

int Pow(int e, int x){
    if (x == -1)return 0;
    int pow = e;
    int ans = 1;
    while(x){
        if(x%2 == 1)ans *= pow;
        pow = pow * pow;
        x/=2;
    }
    return ans;
}
void drawimage(Posi posi){
    for(int l1=0; l1<posi.length; l1++){
        for(int l2 = 0; l2<posi.length; l2++){
            ans_image[l1+posi.x][l2+posi.y] = '*';
        }
    }
}
void solve_treetoimage(int *treenode ,int node_num ,int imagescale){
    for(int i=0;i<imagescale;i++)
        for(int j=0;j<imagescale;j++)
            ans_image[i][j] = '.';

    for(int i = 0; i<node_num ;i++){
        Posi posi(0,0,imagescale);
        while(treenode[i]){
            int mode = treenode[i] %5;
            int dx = ((mode-1) / 2) * (posi.length/2);
            int dy = ((mode-1) % 2) * (posi.length/2);
            posi.x += dx;
            posi.y += dy;
            posi.length /=2;
            treenode[i] /= 5;
        }
        drawimage(posi);
    }

    for(int i=0;i<imagescale;i++){
        ans_image[i][imagescale] = 0;
        printf("%s\n",ans_image[i]);
    }

    return ;
}

void imagetotree(vector<int> &ans,int ** image , int fath_path, int now_layer,Posi posi, int nsew){  //  fath_path +  nsew * 5^(now_layer)
    int now_path = fath_path + nsew * Pow(5 , now_layer -1 );   // 当前节点的编号
    int flag = true;    // 是所有节点颜色一致
    if(posi.length != 1){
        for(int row = posi.x; row < posi.x + posi.length; row++){
            for(int column = posi.y; column < posi.y + posi.length; column++){
                if(image[row][column] != image[posi.x][posi.y]){
                    flag = false;
                    goto next_1;
                }
            }
        }
    }
    next_1:;
    if(flag && image[posi.x][posi.y] == 1){     // 一致且为黑
        ans.push_back(now_path);
        // cout<<now_path<<' '<<posi.x<<' '<<posi.y<<endl;
    }
    else if(!flag) {      //不一致
        for(int mode=1; mode<=4; mode++){
            int dx = ((mode-1) / 2 )* posi.length/2;
            int dy = ((mode-1) % 2 )* posi.length/2;
            Posi p(posi.x + dx, posi.y + dy, posi.length / 2);
            imagetotree(ans, image, now_path, now_layer+1, p, mode);
        }
    }
    //一致且为白全部不用管
    return ;
}
void solve_imagetotree(int **image,int imagescale){

    Posi posi(0,0,imagescale);
    vector<int>ans;
    ans.clear();
    imagetotree(ans, image, 0, 0,posi,0);
    sort(ans.begin(),ans.end());
    for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
        printf("%d ",*it);
    }
    if()
    cout<<"Total number of black nodes = "<<ans.size()<<endl;
    return ;

}

int main()
{
    int n ;
    int cnt = 0;
    while(scanf("%d",&n) == 1){ 
        if(n==0)break;
        cout<<"Image "<<++cnt<<endl;
        if(n == 0) break;
        if(n < 0){
            n = -n;
            int temp_num = 0;
            while(true){
                scanf("%d",&treenode[temp_num]);
                if(treenode[temp_num] != -1)temp_num++;
                else break;
            };
            solve_treetoimage(treenode,temp_num,n);
        }
        else {
            for(int i=0;i<n;i++)image[i] = image_ori[i];
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    char temp;
                    do{
                        temp = getchar();
                    }while(!(temp=='0'||temp == '1'));
                    image_ori[i][j] = temp - '0';
                    //scanf("%d",&image_ori[i][j]);
                }
            }
            solve_imagetotree(image,n);
        }
        cout<<endl;
    }
    return 0;
}
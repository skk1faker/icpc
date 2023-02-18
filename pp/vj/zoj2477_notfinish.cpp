#include<iostream>

using namespace std;

struct posi{
	int x, y;
	int face_id;
	posi(int _x = 0 ,int _y = 0,int _face_id  = 0):x(_x),y(_y),face_id(_face_id){}
	posi(const posi & _test){
		x = _test.x;
		y = _test.y;
		face_id = _test.face_id;
	}
};
struct club_face
{
	int face_id;
	int face_colour[3][3];
	posi neigh_face_posi[4][3];
	bool operator == (const club_face & _test){
		if(face_id != _test.face_id)return false;
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				if(face_colour[i][j] != _test.face_colour[i][j])return false;
			}
		}
		return true;
	}
	club_face(){}
	club_face(int _face_id, int _face_colour[][3], posi _neigh_face_posi[][3]):face_id(_face_id){
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				face_colour[i][j] = _face_colour[i][j];
			}
		}
		for(int i = 0;i < 4;i++){
			for(int j = 0;j<3;j++){
				neigh_face_posi[i][j] = _neigh_face_posi[i][j];
			}
		}
	};
	club_face(const club_face & _copy){
		face_id = _copy.face_id;
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3 ;j++){
				face_colour[i][j] = _copy.face_colour[i][j];
			}
		}
	}
};

struct club
{
	club_face face[6];
	club(club_face _face[]){
		for(int i = 0;i < 6;i++){
			face[i] = _face[i];
		}
		
	}
	club(){}
	bool operator == (const club & _test){
		for(int i = 0;i<6;i++){
			if(this->face[i] == _test.face[i]);
			else return false;
		}
		return true;
	}
	void output_club(){
		for(int i = 0;i<3;i++){
			printf("    ");
			for(int j = 0;j<3;j++){
				printf("%d ",face[4].face_colour[i][j]);
			}
			printf("\n");
		}

		for(int i = 0;i < 3;i++){
			for(int k = 0;k < 4;k++){
				for(int j = 0;j < 3;j++){
					printf("%d ",face[k].face_colour[i][j]);
				}
			}
			printf("\n");
		}

		for(int i = 0;i<3;i++){
			printf("    ");
			for(int j = 0;j<3;j++){
				printf("%d ",face[5].face_colour[i][j]);
			}
			printf("\n");
		}

	}
};

posi clock_wise[3][3] = \
{
	{{2,0},{1,0},{0,0}},\
	{{2,1},{1,1},{0,1}},\
	{{2,2},{1,2},{0,2}},\
};

club_face rotate_face(club club_to_rotate, int club_face_id, int dir){
	int temp[3][3];
	for(int i = 0;i<3;i++){
		for(int j = 0; j< 3;j++){
			temp[i][j] = club_to_rotate.face[club_face_id].face_colour[i][j];
		}
	}
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			int ni = clock_wise[i][j].x;
			int nj = clock_wise[i][j].y;
			if(dir == 1)
				club_to_rotate.face[club_face_id].face_colour[i][j] = temp[ni][nj];
			else 
				club_to_rotate.face[club_face_id].face_colour[ni][nj] = temp[i][j];
		}
	}
	if(dir == -1){
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				int pre_face_id = club_to_rotate.face[club_face_id].neigh_face_posi[0][0].face_id;
				temp[i][j] = club_to_rotate.face[pre_face_id].face_colour[i][j];
			}
		}
		for(int face_num = 0;face_num < 4;face_num++){
			int pre_face_id = club_to_rotate.face[club_face_id].neigh_face_posi[face_num][0].face_id;
			int now_face_id = club_to_rotate.face[club_face_id].neigh_face_posi[(face_num + 1) % 4][0].face_id;
			for(int j = 0; j < 3; j++){
				int px = club_to_rotate.face[club_face_id].neigh_face_posi[face_num][j].x;
				int nx = club_to_rotate.face[club_face_id].neigh_face_posi[(face_num + 1) % 4][j].x;
				int py = club_to_rotate.face[club_face_id].neigh_face_posi[face_num][j].y;
				int ny = club_to_rotate.face[club_face_id].neigh_face_posi[(face_num + 1) % 4][j].y;
				if(face_num <= 2){
					club_to_rotate.face[pre_face_id].face_colour[px][py] = club_to_rotate.face[now_face_id].face_colour[nx][ny];
				}
				else if(face_num == 3){
					club_to_rotate.face[pre_face_id].face_colour[px][py] = temp[nx][ny];
				}
			}

		}
	}
	else {
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				int pre_face_id = club_to_rotate.face[club_face_id].neigh_face_posi[3][0].face_id;
				temp[i][j] = club_to_rotate.face[pre_face_id].face_colour[i][j];
			}
		}
		for(int face_num = 3;face_num >= 0;face_num--){
			int pre_face_id = club_to_rotate.face[club_face_id].neigh_face_posi[face_num][0].face_id;
			int now_face_id = club_to_rotate.face[club_face_id].neigh_face_posi[(face_num - 1 + 4) % 4][0].face_id;
			for(int j = 0; j < 3; j++){
				int px = club_to_rotate.face[club_face_id].neigh_face_posi[face_num][j].x;
				int nx = club_to_rotate.face[club_face_id].neigh_face_posi[(face_num - 1 + 4) % 4][j].x;
				int py = club_to_rotate.face[club_face_id].neigh_face_posi[face_num][j].y;
				int ny = club_to_rotate.face[club_face_id].neigh_face_posi[(face_num - 1 + 4) % 4][j].y;
				if(face_num != 0){
					club_to_rotate.face[pre_face_id].face_colour[px][py] = club_to_rotate.face[now_face_id].face_colour[nx][ny];
				}
				else if(face_num == 0){
					club_to_rotate.face[pre_face_id].face_colour[px][py] = temp[nx][ny];
				}
			}

		}	
	}
	return club_to_rotate.face[club_face_id];	
}

club rotate(club club_to_rotate, int dir){
	for(int i = 0;i < 6;i++){
		club_to_rotate.face[i] = rotate_face(club_to_rotate, i ,dir);
	}
	return club_to_rotate;
}





int main()
{
	return 0;
}

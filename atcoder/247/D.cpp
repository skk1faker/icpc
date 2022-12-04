#include<iostream>
using namespace std;
const int maxx = (int)2e5 + 10;
struct insert_ball
{
	long long ball_id,ball_num;	//x,c
	insert_ball(int x = 0,int c = 0):ball_id(x),ball_num(c){}
}queue[maxx];
int main()
{
	int Q,op;
	int front = 0, rear = 0;// insert in rear
	long long  ans = 0;
	scanf("%d",&Q);
	int x,c;
	while(Q--){
		scanf("%d",&op);
		switch(op){
			case 1:{
					   scanf("%d%d",&x,&c);
					   queue[rear] = insert_ball(x,c);
					   rear = (rear +  1) % maxx;
				   }break;
			case 2:{
					   ans = 0;
					   scanf("%d",&c);
					   while(c != 0){
						   if(queue[front].ball_num - c > 0){
							   queue[front].ball_num -= c;
							   ans += c * queue[front].ball_id;
							   break;
						   }
						   else {
							   ans += queue[front].ball_num * queue[front].ball_id;
							   c -= queue[front].ball_num;
							   front = (front + 1) % maxx;
						   }
					   }
					   printf("%lld\n",ans);
				   }break;

		}

	}

}

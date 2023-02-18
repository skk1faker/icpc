//lrj--186枚举带有重复元素的集合

#include<iostream>
using namespace std;

const int maxx = (int)1e3;

int num = 0;
void get_permutation(int A[], int now_finish_num, int need_finish_num, int B[]){
    if(now_finish_num == need_finish_num){
        num++;
        for(int i=0;i<now_finish_num;i++){
            printf("%d ",B[i]);
        }cout<<endl;
        return;   
    }
    for(int i=0;i<need_finish_num;i++){
        //当A有序的时候使用下面代码判断以前是否用过
        // if(i && A[i] == A[i-1])continue;    // A[i] 这个值曾经在now_finish_num位置处用过，所以跳过（注意，A是经过排序的，所以才能用这样的方式知道以前是否用过A[i],否则只能使用下面的方法）
        //当A无序的时候使用下面代码判断以前是否用过！但是最好使用排序之后的结果，这样更加能节约时间
        bool flag = false ;
        for(int j = 0; j < i; j++){
            if(A[i] == A[j]){   // 查看以前是否使用过A[i],否则会造成重复
                flag = true;
                break;
            }
        }
        if(flag)continue;
        int c0 = 0 ,c1 = 0;
        for(int j=0;j<need_finish_num;j++)if(A[i] == A[j])c0++;
        for(int j=0;j<now_finish_num;j++)if(A[i] == B[j])c1++;
        if(c0>c1){
            B[now_finish_num] = A[i];
            get_permutation(A, now_finish_num + 1, need_finish_num, B);
        }

    }
    return 0;
}

int main()
{
    int A[maxx];
    int B[maxx];
    int n = 0;
    while(scanf("%d",&A[n]) == 1)n++;
    get_permutation(A, 0, n, B);
    cout<<num<<endl;
    return 0;
}
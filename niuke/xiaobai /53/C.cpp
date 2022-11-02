#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

struct word
{
    string w;
    int k;
    bool operator < (const word & w1)
    {
        // if (fabs(this->k - w1.k) < 1e-18)
        if(this->k == w1.k){
            return this->w < w1.w;
        }
        return this->k < w1.k;
    }
}book[100];

int main()
{
    word ans = {""};
    // scanf("%s",ans.w);
    cin>>ans.w;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        // scanf("%s",book[i].w);
        cin>>book[i].w;
        book[i].k = 0;
        if(book[i].w.length() == ans.w.length()){
            for(int j = 0;j < book[i].w.length();j++){
                book[i].k += (int)(book[i].w[j] == ans.w[j]);
            }
        }
    }
    sort(book,book+n);
    int pre = book[n-1].k;
    for(int i=0;i<n;i++){
        if(pre == book[i].k){
            cout<<book[i].w<<endl;
        }
    }
}
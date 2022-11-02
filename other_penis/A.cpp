#include<iostream>	
#include <sstream>
#include<string>
using namespace std;
int main()
{
    string s;
    int x[1000];
    cin>>s;
    stringstream ss(s);
    int n = 0;
    string str;
    while(getline(ss,str,',')){
        // x[n] = atoi(str.c_str());
        x[n] = atoi((char *)str.data());
        cout<<x[n]<<endl;
        n++;
    }


    return 0;
}
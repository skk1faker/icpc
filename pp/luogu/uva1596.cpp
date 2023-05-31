#include<bits/stdc++.h>
#include <cctype>
#define DEBUG 0
#define DEBUG1 0
using namespace std;

struct arr{
  int length;
  map<int,int>value_list;
};

map<string,struct arr> arr_map;

void init_map(char *s){
  int i = 0;
  string name = "";
  while(s[i] && isalpha(s[i])){
    name+=s[i];
    i++;
  }
  i++;
  int arr_length = 0;
  while(s[i] && isdigit(s[i])){
    arr_length *= 10;
    arr_length += s[i] - '0';
    i++;
  }
  arr_map[name].length = arr_length;
}

int getvalue(int l,int r,char * s){
  if(isdigit(s[l])){
    int ans = 0;
    for(int i = l;i <= r;i++ ){
      ans *= 10;
      ans += s[i] - '0';
    }
    return ans;
  }
  string name_array = "";
  while(l < r && isalpha(s[l])){
      name_array+= s[l];
      l++;
  }
  int temp_value = getvalue(l + 1, r - 1, s);
  if(arr_map[name_array].length <= temp_value || arr_map[name_array].value_list.count(temp_value) == 0){
    return -1; 
  };
  return arr_map[name_array].value_list[temp_value];
}

int parse_string(int l,int r,char *s){
  int equal_posi;
  for(equal_posi = l;equal_posi <=r && s[equal_posi] != '=';equal_posi++);
  if(s[equal_posi] != '='){
    init_map(s);
    return 0;
  }
  string name = "";
  while(l < equal_posi && isalpha(s[l])){
    name += s[l];
    l++;
  }
  int \
  val_1 = getvalue(l + 1, equal_posi - 2, s),\
  val_2 = getvalue(equal_posi + 1, r, s);
  if(val_1 == -1 || val_2 == -1 || arr_map[name].length <= val_1){
    return -1;
  }
  arr_map[name].value_list[val_1] = val_2;
  return 0;
}


int main()
{
  int count = 0,ans = 0,posi = 0;
  while(count <= 1){
    char s[81];
    scanf("%s",s);
    if(s[0] == '.'){
      
      if(count == 0)cout<<ans<<endl;
      count++;
      ans = 0;
      posi = 0;
      for(map<string,struct arr>::iterator iter = arr_map.begin();iter != arr_map.end();iter++){
        iter->second.value_list.clear();
      }
      arr_map.clear();
      continue;
    }
    posi++;
    if(ans == 0 &&  parse_string(0, strlen(s) - 1, s) == -1)ans = posi;
    count = 0;
  }
  return 0;
}

/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    b.cpp
*   username:     skt1faker
*   create time:  10:41  2023.05.14
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
bool doesValidArrayExist(vector<int>& derived) {

  int n= derived.size();
  int ans = 0;
  for(int i = 0;i < n;i++){
    ans = ans ^ derived[i];
  }
  return ans == 0;
}


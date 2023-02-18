#include <bits/stdc++.h>

using namespace std;

set<int> ans;
struct interval_point {
  long long x, y, status, id, h; // status == 1 in , status == 0 out;
  struct interval_point *next;
  bool operator<(const interval_point &a) const {
    if (this->x != a.x)
      return this->x < a.x;
    if (this->status != a.status)
      return this->status > a.status;
    return this->y < a.y; // line of sight order,
  }
};

vector<interval_point> ans_vec;
void insert_line(struct interval_point *head, struct interval_point temp) {
  interval_point *need_insert, *now_posi = head->next, *pre_posi = head;
  need_insert = (interval_point *)malloc(sizeof(interval_point));
  memcpy(need_insert, &temp, sizeof(interval_point));
  while (now_posi != NULL) {
    if (now_posi->y > temp.y)
      break;
    pre_posi = now_posi;
    now_posi = now_posi->next;
  }
  need_insert->next = now_posi;
  pre_posi->next = need_insert;
}

void delete_line(struct interval_point *head, struct interval_point temp) {
  interval_point *now_posi = head->next, *pre_posi = head;
  while (now_posi->id != temp.id) {
    pre_posi = now_posi;
    now_posi = now_posi->next;
  }
  pre_posi->next = now_posi->next;
  free(now_posi);
}

void get_ans(struct interval_point *head) {
  interval_point *now_posi = head->next;
  int now_tall = 0;
  while (now_posi != NULL) {
    if (now_tall < now_posi->h) {
      now_tall = now_posi->h;
      if (ans.count(now_posi->id) == 0) {
        ans.insert(now_posi->id);
        //printf("%lld ", now_posi->id);
        ans_vec.push_back(*now_posi);
      }
    }
    now_posi = now_posi->next;
  }
}
int main() {
  int n, Case = 1;
  vector<interval_point> vip;
  while (scanf("%d", &n) == 1 && n != 0) {
    if(Case != 1)printf("\n");
    printf("For map #%d, the visible buildings are numbered as follows:\n",
           Case++);
    vip.clear();
    ans.clear();
    ans_vec.clear();
    for (int i = 1; i <= n; i++) {
      long long x, y, l, w, h;
      scanf("%lld%lld%lld%lld%lld", &x, &y, &l, &w, &h);
      interval_point temp_1{x, y, 1, i, h}, temp_2{x + l + 1, y, 0, i, h};
      vip.push_back(temp_1);
      vip.push_back(temp_2);
    }
    sort(vip.begin(), vip.end());
    struct interval_point *head =
        (interval_point *)malloc(sizeof(interval_point));
    head->next = NULL;
    for (int i = 0; i < 2 * n; i++) {
      if (vip[i].status == 0) {
        delete_line(head, vip[i]);
      } else {
        insert_line(head, vip[i]);
      }
      if (i + 1 == 2 * n || vip[i].x != vip[i + 1].x)
        get_ans(head);
    }
    sort(ans_vec.begin(),ans_vec.end());
    int ans_length = ans_vec.size();
    for(int i = 0;i < ans_length;i++){
      printf("%lld",ans_vec[i].id);
      if(i != ans_length - 1)
        printf(" ");
    else printf("\n");
    }
  }
  return 0;
}

#include <iostream>
using namespace std;
struct line {
  int val;
  struct line *next, *pre;
};

int main() {
  int n, k, m;
  while (scanf("%d%d%d", &n, &k, &m) == 3 && n != 0) {
    struct line *head = (struct line *)malloc(sizeof(struct line));
    head->next = head;
    head->pre = head;
    head->val = 1;
    for (int i = 2; i <= n; i++) {
      head->pre->next = (struct line *)malloc(sizeof(struct line));
      head->pre->next->val = i;
      head->pre->next->pre = head->pre;
      head->pre->next->next = head;
      head->pre = head->pre->next;
    }
    struct line *posi[2] = {head->pre, head};
    while (n) {
      for (int i = 0; i < k; i++)
        posi[0] = posi[0]->next;
      for (int i = 0; i < m; i++)
        posi[1] = posi[1]->pre;
      if (posi[0] != posi[1])
        n--;
      n--;
      printf("%3d", posi[0]->val);
      if (posi[0] != posi[1]) {
        printf("%3d", posi[1]->val);
      }
      int flag = 0;
      if (posi[0] != posi[1])
        flag = 1;
      struct line *posi_next = posi[0]->pre;
      if(n > 0)printf(",");
      posi[0]->pre->next = posi[0]->next;
      posi[0]->next->pre = posi[0]->pre;

      free(posi[0]);
      posi[0] = posi_next;
      if (flag) {
        posi_next = posi[1]->next;
        posi[1]->pre->next = posi[1]->next;
        posi[1]->next->pre = posi[1]->pre;
        if(posi[0] == posi[1])posi[0] = posi[0]->pre;
        free(posi[1]);
        posi[1] = posi_next;
      } else
        posi[1] = posi[0]->next;
    }
    printf("\n");
  }
}

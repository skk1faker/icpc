#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class STU {
public:
  string SID;
  string CID;
  string name;
  int score[4];

  STU(string id[], int *score = NULL) : SID(id[0]), CID(id[1]), name(id[2]) {
    for (int i = 0; i < 4; i++) {
      this->score[i] = score[i];
    }
    name_next = NULL;
    name_pre = NULL;
    cid_next = NULL;
    cid_pre = NULL;
  }
  STU *cid_next, *cid_pre, *name_next, *name_pre;
};
class SPMS {
private:
  // 可以使用链表写的更加复杂
  map<string, STU *> sid_order;
  map<string, pair<STU *, STU *>> cid_order;
  map<string, pair<STU *, STU *>> name_order;
  int rank_tree[402]; // 树状树组维护排名
  void add_val(int posi, int val = 1) {
    for (posi = 401 - posi; posi <= 401; posi += (posi & (-posi))) {
      rank_tree[posi] += val;
    }
  }
  int check(int posi) {
    if(401 - posi == 0)return 0;
    int ans = 0;
    for (posi = 401 - posi; posi > 0; posi -= (posi & (-posi))) {
      ans += rank_tree[posi];
    }
    return ans;
  }

public:
  SPMS() { memset(rank_tree, 0, sizeof(rank_tree)); }
  void meun() {
    int opt;
    // https://blog.csdn.net/baiqishijkh/article/details/79236202
    while (true) {

      printf("Welcome to Student Performance Management System (SPMS).\n"
             "\n"
             "1 - Add\n"
             "2 - Remove\n"
             "3 - Query\n"
             "4 - Show ranking\n"
             "5 - Show Statistics\n"
             "0 - Exit\n\n");
      scanf("%d", &opt);
      switch (opt) {
      case 0: {
        return;
      } break;
      case 1: {
        add_student();
      } break;
      case 2: {
        del_student();
      } break;
      case 3: {
        query_student();
      } break;
      case 4: {
        printf("Showing the ranklist hurts students' self-esteem. Don't do "
               "that.\n");
      } break;
      case 5: {
        show_statistics();
      } break;
      }
    }
  }
  bool add_student() {
    string input[3];
    int score[4];
    while (true) {
      printf("Please enter the SID, CID, name and four scores. Enter 0 to "
             "finish.\n");

      cin >> input[0];
      if (input[0].length() == 1 && input[0][0] == '0')
        return true;
      for (int i = 1; i < 3; i++)
        cin >> input[i];
      for (int i = 0; i < 4; i++)
        scanf("%d", &score[i]);
      STU *student = new STU(input, score);
      // check SID has been inserted;
      if (sid_order.count(input[0]) == 1) {
        printf("Duplicated SID.\n");
        continue;
      };
      add_val(score[0] + score[1] + score[2] + score[3], 1);
      // TODO : add student
      sid_order[input[0]] = student;
      if (cid_order.count(input[1]) == 0) { // 链表为空
        student->cid_next = NULL;
        student->cid_pre = NULL;
        cid_order[input[1]] = make_pair(student, student);
      } else {
        student->cid_pre = cid_order[input[1]].second;
        student->cid_next = NULL;
        cid_order[input[1]].second->cid_next = student;
        cid_order[input[1]].second = student;
      }
      if (name_order.count(input[2]) == 0) {
        student->name_next = NULL;
        student->name_pre = NULL;
        name_order[input[2]] = make_pair(student, student);
      } else {
        student->name_next = NULL;
        student->name_pre = name_order[input[2]].second;
        name_order[input[2]].second->name_next = student;
        name_order[input[2]].second = student;
      }
    }
  }
  bool del_student() {

    while (true) {

      printf("Please enter SID or name. Enter 0 to finish.\n");
      string input;
      cin >> input;
      if (input[0] == '0' && input.length() == 1) {
        return true;
      }
      if (isalpha(input[0])) { // name
        if (name_order.count(input) == 0) {
          printf("0 student(s) removed.\n");
          continue;
        }
        STU *name_posi = name_order[input].first;
        int num = 0;
        for (; name_posi != NULL; name_posi = name_posi->name_next) {
          int temp_total = 0;
          for (int i = 0; i < 4; i++)
            temp_total += name_posi->score[i];
          add_val(temp_total, -1);
          num++;
          // 1. delete the lash element  pre == null
          // 2. delete the head element  next == null
          // 3. delete the last and head element pre == null && next == null
          if (name_posi->cid_pre == NULL)
            cid_order[name_posi->CID].first = name_posi->cid_next;
          else
            name_posi->cid_pre->cid_next = name_posi->cid_next;
          if (name_posi->cid_next == NULL)
            cid_order[name_posi->CID].second = name_posi->cid_pre;
          else
            name_posi->cid_next->cid_pre = name_posi->cid_pre;
          sid_order.erase(name_posi->SID);
          if (cid_order[name_posi->CID].first == NULL &&
              cid_order[name_posi->CID].second == NULL)
            cid_order.erase(name_posi->CID);
          delete (name_posi);
        }
        if (num >= 1)
          printf("%d student(s) removed.\n", num);
        name_order.erase(input);
      } else { // sid

        if (sid_order.count(input) == 0) {
          printf("0 student(s) removed.\n");
          continue;
        }
        STU *sid = sid_order[input];
        int temp_total = 0;
        for (int i = 0; i < 4; i++)
          temp_total += sid->score[i];
        add_val(temp_total, -1);
        sid_order.erase(input);

        printf("1 student(s) removed.\n");
        if (sid->cid_pre == NULL) {
          cid_order[sid->CID].first = sid->cid_next;
        } else {
          sid->cid_pre->cid_next = sid->cid_next;
        }
        if (sid->cid_next == NULL) {
          cid_order[sid->CID].second = sid->cid_pre;
        } else {
          sid->cid_next->cid_pre = sid->cid_pre;
        }

        if (cid_order[sid->CID].first == NULL &&
            cid_order[sid->CID].second == NULL) {
          cid_order.erase(sid->CID);
        }

        if (sid->name_pre == NULL) {
          name_order[sid->name].first = sid->name_next;
        } else {
          sid->name_pre->name_next = sid->name_next;
        }
        if (sid->name_next == NULL) {
          name_order[sid->name].second = sid->name_pre;
        } else {
          sid->name_next->name_pre = sid->name_pre;
        }

        if (name_order[sid->name].first == NULL &&
            name_order[sid->name].second == NULL) {
          name_order.erase(sid->name);
        }
        delete (sid);
      }
    }
  }
  bool query_student() {
    while (true) {
      string input;
      printf("Please enter SID or name. Enter 0 to finish.\n");
      cin >> input;
      if (input.length() == 1 && input[0] == '0')
        return true;
      if (isalpha(input[0])) { // name
        if (name_order.count(input) == 0)
          continue;
        for (STU *name_posi = name_order[input].first; name_posi != NULL;
             name_posi = name_posi->name_next) {
          int total_score = 0;
          for (int i = 0; i < 4; i++)
            total_score += name_posi->score[i];
          printf("%d %s %s %s ", check(total_score + 1) + 1, name_posi->SID.c_str(),
                 name_posi->CID.c_str(), name_posi->name.c_str());
          for (int i = 0; i < 4; i++)
            printf("%d ", name_posi->score[i]);
          printf("%d %.2lf\n", total_score, (float)total_score / 4 + (1e-5));
        }

      } else {
        if (sid_order.count(input) == 0)
          continue;
        STU *sid = sid_order[input];
        int total_score = 0;
        for (int i = 0; i < 4; i++)
          total_score += sid->score[i];
        printf("%d %s %s %s ", check(total_score + 1) + 1, sid->SID.c_str(),
               sid->CID.c_str(), sid->name.c_str());
        for (int i = 0; i < 4; i++)
          printf("%d ", sid->score[i]);
        printf("%d %.2lf\n", total_score, (float)total_score / 4 + (1e-5));
      }
    }
  }
  bool show_statistics() {
    printf("Please enter class ID, 0 for the whole statistics.\n");
    string input;
    cin >> input;
    if (!(input.length() == 1 && input[0] == '0')) {

      string subject[4] = {"Chinese", "Mathematics", "English", "Programming"};

      for (int i = 0; i < 4; i++) {
        double avg = 0;
        int pass_num = 0, upass_num = 0;
        if (cid_order.count(input) == 1) {
          for (STU *cid = cid_order[input].first; cid != NULL;
               cid = cid->cid_next) {
            if (cid->score[i] >= 60)
              pass_num++;
            else
              upass_num++;
            avg += cid->score[i];
          }
          printf("%s\n"
                 "Average Score: %.2lf\n"
                 "Number of passed students: %d\n"
                 "Number of failed students: %d\n\n",
                 subject[i].c_str(), avg / (pass_num + upass_num) + 1e-5, pass_num,
                 upass_num);
        } else {
          printf("%s\n"
                 "Average Score: -nan\n"
                 "Number of passed students: %d\n"
                 "Number of failed students: %d\n\n",
                 subject[i].c_str(), pass_num, upass_num);
        }
      }
      printf("Overall:\n");
      int pass_num[5] = {
          0}; // 全部初始化为0， pass_num[5]= {1};初始化为1 0 0 0 0
      if (cid_order.count(input) == 1) {
        for (STU *cid = cid_order[input].first; cid != NULL;
             cid = cid->cid_next) {
          int now_pass = 0;
          for (int i = 0; i < 4; i++) {
            if (cid->score[i] >= 60)
              now_pass++;
          }
          pass_num[now_pass]++;
          for (int i = now_pass - 1; i >= 1; i--) {
            pass_num[i]++;
          }
        }
      }
      printf("Number of students who passed all subjects: %d\n"
             "Number of students who passed 3 or more subjects: %d\n"
             "Number of students who passed 2 or more subjects: %d\n"
             "Number of students who passed 1 or more subjects: %d\n"
             "Number of students who failed all subjects: %d\n\n",
             pass_num[4], pass_num[3], pass_num[2], pass_num[1], pass_num[0]);
    } else {
      string subject[4] = {"Chinese", "Mathematics", "English", "Programming"};
      for (int i = 0; i < 4; i++) {
        double avg = 0;
        int pass_num = 0, upass_num = 0;
        for (map<string, STU *>::iterator iter = sid_order.begin();
             iter != sid_order.end(); iter++) {
          if (iter->second->score[i] >= 60)
            pass_num += 1;
          else
            upass_num += 1;
          avg += iter->second->score[i];
        }
        if (pass_num + upass_num > 0) {
          printf("%s\n"
                 "Average Score: %.2lf\n"
                 "Number of passed students: %d\n"
                 "Number of failed students: %d\n\n",
                 subject[i].c_str(), avg / (pass_num + upass_num) + (1e-5), pass_num,
                 upass_num);
        } else {
          printf("%s\n"
                 "Average Score: -nan\n"
                 "Number of passed students: %d\n"
                 "Number of failed students: %d\n\n",
                 subject[i].c_str(), pass_num, upass_num);
        }
      }
      // overall
      printf("Overall:\n");
      int pass_num[5] = {
          0}; // 全部初始化为0， pass_num[5]= {1};初始化为1 0 0 0 0
      for (map<string, STU *>::iterator iter = sid_order.begin();
           iter != sid_order.end(); iter++) {
        int now_pass = 0;
        for (int i = 0; i < 4; i++) {
          if (iter->second->score[i] >= 60)
            now_pass++;
        }
        pass_num[now_pass]++;
        for (int i = now_pass - 1; i >= 1; i--) {
          pass_num[i]++;
        }
      }
      printf("Number of students who passed all subjects: %d\n"
             "Number of students who passed 3 or more subjects: %d\n"
             "Number of students who passed 2 or more subjects: %d\n"
             "Number of students who passed 1 or more subjects: %d\n"
             "Number of students who failed all subjects: %d\n\n",
             pass_num[4], pass_num[3], pass_num[2], pass_num[1], pass_num[0]);
    }
    return true;
  }
};
int main() {
  SPMS database;
  database.meun();
  return 0;
}

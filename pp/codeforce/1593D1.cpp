#include<map>
#include<vector>
#include<iostream>
#include<set>
using namespace std;

/*
	将大于number[posi]的值的因子分解搞出来，然后看最大的分解能不能数量超过n/2-same

*/

set<int> divs(int num)
{
	set<int> div_set;

	for(int i=1;i*i<=num;i++){
		if(num%i==0){
			div_set.insert(num/i);
			div_set.insert(i);
		}
	}

	return div_set;
}

int main()
{
	int T;
	cin>>T;
	while(T--){
		int n;
		int number[45];
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&number[i]);
		int k = -1;
		for(int i=0;i<n;i++){
			int min_val = number[i];
			vector<int> track_list;
			int same=0;
			for(int i=0;i<n;i++){
				if(min_val<number[i])track_list.push_back(number[i]-min_val);
				else if (min_val==number[i])same++;
			
			}
			if(track_list.size()+same<n/2)continue;			//必然不会产生结果
			if(same>=n/2){			//表示可以使用任意大的数
				k=-1;
				break;
			}


			set<int> num_div;
			map<int,int> map_div;
			vector<int>::iterator iter_vec;
			set<int>::iterator iter_set;



			for(iter_vec = track_list.begin();iter_vec != track_list.end();iter_vec++){
				num_div = divs(*iter_vec);
				for (iter_set = num_div.begin();iter_set!=num_div.end();iter_set++){
					map_div[*iter_set]++;
				}
			}

			map<int,int>::iterator iter_map;


			for(iter_map = map_div.begin();iter_map !=map_div.end();iter_map++){
				if(iter_map->second >= n/2-same){
					k = max(k, iter_map->first);
				}
			}
		}
		cout<<k<<endl;
	}
	return 0;
}




































/*
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

set<int> divs(int n) {  
    set<int> d;
    for (int dd = 1; dd * dd <= n; dd++)
        if (n % dd == 0) {
            d.insert(n / dd);
            d.insert(dd);
        }
    return d;
}

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
        int k = -1;

        forn(i, n) {
            int minv = a[i];
            int same = 0;
            vector<int> d;
            forn(j, n) {
                if (a[j] == minv)
                    same++;
                else if (a[j] > minv)
                    d.push_back(a[j] - minv);
            }
            if (same >= n / 2) {
                k = INT_MAX;
                continue;
            }
            map<int,int> div_counts;
            for (int di: d)
                for (int dd: divs(di))
                    div_counts[dd]++;
            for (auto p: div_counts)
                if (p.second >= n / 2 - same)
                    k = max(k, p.first);
        }

        cout << (k == INT_MAX ? -1 : k) << endl;
    }
}

*/

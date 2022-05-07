#include "paint.h"
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

int minimumInstructions(
	int n, int m, int k, vector<int> c, vector<int> a, vector<vector<int>> b)
{
	int ans = 1;
	vector<set<int>> preference(m);
	vector<vector<int>> like_color(k);
	vector<bool> can_start(n - m + 1);
	for(int i = 0; i < m; i++) for(int j = 0; j < a[i]; j++)
	{
		like_color[b[i][j]].push_back(i);
		preference[i].insert(b[i][j]);
	}
	for(int i = 0; i <= n - m; i++)
	{
		i = min(i, n - m);
		for(int j = 0; j < like_color[c[i]].size(); j++)
		{
			bool flag = 1;
			int k = like_color[c[i]][j], ii = i;
			for(int x = 0; x < m; x++)
			{
				if(preference[k % m].count(c[ii]))
				{
					ii++;
					k++;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				can_start[i] = 1;
				break;
			}
		}
	}
	if(!can_start[0] || !can_start[n - m]) return -1;
	int i = 1, j = m;
	while(i < n - m + 1)
	{
		ans++;
		int maxi = -1;
		for(int x = i; x <= min(j, n - m); x++) if(can_start[x]) maxi = max(maxi, x);
		if(maxi == -1) return -1;
		i = maxi + 1;
		j = maxi + m;
	}
	return ans;
}
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

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c1 = 0, c2 = 0, c3 = 0; cin >> n;
	vector<pair<int, pii>> ans(5000, make_pair(-1, make_pair(-1, -1)));
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if(a == 1)
		{
			ans[c1].first = i + 1;
			c1++;
		}
		else if(a == 2)
		{
			ans[c2].second.first = i + 1;
			c2++;
		}
		else
		{
			ans[c3].second.second = i + 1;
			c3++;
		}
	}
	int k = 0;
	for(auto x : ans)
	{
		if(x.first > -1 && x.second.first > -1 && x.second.second > -1) k++;
		else break;
	}
	cout << k << endl;
	for(int i = 0; i < k; i++)
	{
		cout << ans[i].first << ' ';
		cout << ans[i].second.first << ' ';
		cout << ans[i]	.second.second << endl;
	}

	return 0;
}
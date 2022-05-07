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
	int t; cin >> t;
	while(t--)
	{
		int n, k; cin >> n >> k;
		bool flag = 0;
		vector<pii> p(n);
		for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
		for(int i = 0; i < n; i++)
		{
			bool ok = 1;
			for(int j = 0; j < n; j++)
			{
				int d = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
				ok &= d <= k;
			}
			if(ok)
			{
				flag = 1;
				break;
			}
		}
		cout << (flag ? 1 : -1) << endl;
	}

	return 0;
}
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
		ll n, ans = 0, l = 0; cin >> n;
		ll r = n - 2;
		map<int, ll> freq;
		vector<ll> c;
		for(int i = 0; i < n; i++)
		{
			int a; cin >> a;
			freq[a]++;
		}
		for(auto x : freq) c.push_back(x.second);
		sort(c.begin(), c.end());
		while(l <= r)
		{
			ll m = (l + r)/2;
			bool ok = 1;
			for(ll i = c.size() - 1; i > -1; i--)
				if(c[i] + (c[i] - 1) * m + c.size() - i - 1 > n)
				{
					ok = 0;
					break;
				}
			if(ok)
			{
				ans = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		cout << ans << endl;
	}

	return 0;
}
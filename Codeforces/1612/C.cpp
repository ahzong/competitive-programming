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
		ll k, x; cin >> k >> x;
		if(k * k < x)
		{
			cout << 2 * k - 1 << endl;
			continue;
		}
		ll l = 1, r = 2 * k - 1, ans = 0;
		while(l <= r)
		{
			ll m = (l + r)/2, emotes;
			if(m <= k) emotes = m * (m + 1)/2;
			else
			{
				ll y = 2 * k - m - 1;
				emotes = k * k - y * (y + 1)/2;
			}
			if(emotes >= x) r = m - 1;
			else
			{
				ans = m;
				l = m + 1;
			}
		}
		cout << ans + 1 << endl;
	}

	return 0;
}
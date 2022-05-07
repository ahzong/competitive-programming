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
	int n; cin >> n;
	ll l, r, x, ans = 0; cin >>  l >> r >> x;
	vector<ll> c(n);
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int mask = 1; mask < (1<<n); mask++)
	{
		int i = 0, _mask = mask;
		ll total = 0, maxi = 0, mini = INF64;
		while(_mask)
		{
			if(_mask & 1)
			{
				total += c[i];
				maxi = max(maxi, c[i]);
				mini = min(mini, c[i]);
			}
			_mask /= 2;
			i++;
		}
		ans += maxi - mini >= x && total >= l && total <= r;
	}
	cout << ans;

	return 0;
}
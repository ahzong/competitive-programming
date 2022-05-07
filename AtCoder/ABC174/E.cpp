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
	ll k, l = 1, r = 1; cin >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		r = max(r, a[i]);
	}
	ll ans = r;
	while(l <= r)
	{
		ll m = (l + r)/2, c = 0;
		for(int i = 0; i < n; i++) c += a[i]/m - (!(a[i] % m));
		if(c > k) l = m + 1;
		else
		{
			ans = m;
			r = m - 1;
		}
	}
	cout << ans;

	return 0;
}
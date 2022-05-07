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
		ll s = 0;
		int n; cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = n - 1; i; i--) s += abs(a[i] - a[i - 1]);
		ll ans = s - max(abs(a[n - 1] - a[n - 2]), abs(a[1] - a[0]));
		for(int i = n - 1; i > 1; i--)
		{
			ll d1 = abs(a[i] - a[i - 1]), d2 = abs(a[i - 1] - a[i - 2]);
			ans = min(ans, s - d1 - d2 + abs(a[i] - a[i - 2]));
		}
		cout << ans << endl;
	}

	return 0;
}
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
	ll n, ans = 0; cin >> n;
	vector<ll> a(n);
	for(ll i = 0; i < n - 1; i++) cin >> a[i];
	for(ll i = -3 * n; i <= 3 * n; i++)
	{
		ll sum = 0;
		bool ok = 1;
		vector<int> freq(n + 1);
		for(ll j = 0; j < n - 1; j++)
		{
			ll p = abs(a[j] - i);
			if(p < 1 || p > n)
			{
				ok = 0;
				break;
			}
			sum += p;
			freq[p]++;
			if(freq[p] == 2)
			{
				ok = 0;
				break;
			}
		}
		if(ok) ans += (n * (n + 1))/2 - sum;
	}
	cout << ans;

	return 0;
}
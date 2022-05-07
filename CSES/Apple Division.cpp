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
	ll s = 0, ans = INF64;
	vector<ll> p(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		s += p[i];
	}
	for(int i = 1; i < (1<<n); i++)
	{
		int ii = i, j = 0;
		ll cur = 0;
		while(ii)
		{
			if(ii & 1) cur += p[j];
			j++;
			ii /= 2;
		}
		ans = min(ans, abs(2 * cur - s));
	}
	cout << ans;

	return 0;
}
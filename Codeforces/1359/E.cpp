#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 998244353;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

vector<ll> fact;

ll fastpow(ll base, ll index)
{
	ll ret = 1;
	while(index)
	{
		if(index & 1) ret = (ret * base) % MOD;
		base = (base * base) % MOD;
		index /= 2;
	}
	return ret;
}

ll ncr(ll n, ll r)
{
	ll ret = fact[n] * fastpow(fact[n - r], MOD - 2) % MOD;
	return ret * fastpow(fact[r], MOD - 2) % MOD;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k, ans = 0; cin >> n >> k;
	fact.resize(n + 1);
	fact[0] = 1;
	for(ll i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
	for(ll i = 1; n/i >= k; i++) ans = (ans + ncr(n/i - 1, k - 1)) % MOD;
	cout << ans;

	return 0;
}
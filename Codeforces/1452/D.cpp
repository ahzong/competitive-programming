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

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin >> n;
	vector<ll> fib(n + 1, 1);
	for(ll i = 3; i <= n; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	cout << fib[n] * fastpow(fastpow(2, n), MOD - 2) % MOD;

	return 0;
}
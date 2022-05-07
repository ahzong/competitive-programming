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

ll spf[1000001];

void sieve()
{
	for(ll i = 1; i < 1000001; i++) spf[i] = (i & 1) ? i : 2;
	for(ll i = 3; i * i < 1000001; i++) if(spf[i] == i)
		for(ll j = i * i; j < 1000001; j += i) if(spf[j] == j) spf[j] = i;
}

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
	sieve();
	ll n, l = 1, ans = 0; cin >> n;
	vector<ll> a(n);
	map<ll, ll> total;
	for(ll i = 0; i < n; i++)
	{
		cin >> a[i];
		ll aa = a[i];
		map<ll, ll> cur;
		while(aa > 1)
		{
			cur[spf[aa]]++;
			l = l * fastpow(spf[aa], max(0LL, cur[spf[aa]] - total[spf[aa]])) % MOD;
			total[spf[aa]] = max(total[spf[aa]], cur[spf[aa]]);
			aa /= spf[aa];
		}
	}
	for(ll x : a) ans = (ans + l * fastpow(x, MOD - 2) % MOD) % MOD;
	cout << ans;

	return 0;
}
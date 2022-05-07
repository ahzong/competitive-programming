#include "hexagon.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll modpow(ll base, ll index)
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

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}

ll mult(ll a, ll b)
{
	return (a * b) % MOD;
}

ll divide(ll a, ll b)
{
	return a * modpow(b, MOD - 2) % MOD;
}

int draw_territory(int N, int A, int B, vector<int> D, vector<int> L) {
	ll n = N, a = A, b = B;
	vector<ll> d(n), l(n);
	for(int i = 0; i < n; i++) d[i] = D[i];
	for(int i = 0; i < n; i++) l[i] = L[i];

	ll ans = divide(mult(mult(a, l[0] + 1), l[0] + 2), 2);
	ans = add(ans, divide(mult(mult(b, l[0]), mult(l[0] + 1, 2 * l[0] + 1)), 6));
	ans = add(ans, divide(mult(mult(b, l[0]), l[0] + 1), 2));

	return ans;
}
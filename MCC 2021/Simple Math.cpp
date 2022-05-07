#include <bits/stdc++.h>
#include "data.h"

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

vector<ll> fact(5e4 + 1, 1);

ll pow2(ll base, ll index)
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
	return fact[n] * pow2(fact[n - r], MOD - 2) % MOD * pow2(fact[r], MOD - 2) % MOD;
}

int main()
{
	for(int i = 1; i < 5e4 + 1; i++) fact[i] = (i * fact[i - 1]) % MOD;
	if(P == 1)
	{
		ll ans = 0;
		for(int i = 0; i < N; i++) ans = (ans + A[i]) % MOD;
		cout << ans * pow2(2, N - 1) % MOD;
	}
	else if(P == 2)
	{
		ll ans = 1;
		for(int i = 0; i < N; i++) ans = ans * (A[i] + 1) % MOD;
		cout << (!ans ? (ll) 1e9 + 6 : ans - 1);
	}
	else
	{
		ll ans = 0;
		for(int i = 0; i < 32; i++)
		{
			ll oc = 0, cur = 0;
			for(int j = 0; j < N; j++)
			{
				oc += (A[j] & 1);
				A[j] /= 2;
			}
			for(int j = 1; j <= oc; j += 2) cur = (cur + ncr(oc, j)) % MOD;
			ans = (ans + (cur * pow2(2, N - oc) % MOD * pow2(2, i) % MOD)) % MOD;
		}
		cout << ans;
	}

	return 0;
}
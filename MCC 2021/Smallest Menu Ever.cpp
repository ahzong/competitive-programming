#include <bits/stdc++.h>
#include "data.h"

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main()
{
	sort(layer.begin(), layer.end());
	ll prod = 1;
	ll ans = 0;
	for(int i = 0; i < N; i++)
	{
		prod = (prod * layer[i]) % MOD;
		ans = (ans + prod) % MOD;
	}
	cout << ans;

	return 0;
}
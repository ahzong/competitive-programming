#include <bits/stdc++.h>
// #include "data.h"

using namespace std;
typedef long long ll;

int main()
{
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	int N; cin >> N;
	ll A; cin >> A;
	vector<ll> R(N - 1);
	for(int i = 0; i < N - 1; i++) cin >> R[i];
	N--;
	sort(R.begin(), R.end(), greater<ll>());
	for(int i = 0; i < N; i++) R[i] *= R[i];
	ll x = 0;
	for(int i = 0; i < N; i++) x += (i & 1) ? -R[i] : R[i];
	x += A;
	for(int i = 0; i < N + 1; i++)
	{
		if(floor(sqrtl(x)) == ceil(sqrtl(x)))
		{
			ll ans = floor(sqrtl(x));
			bool ok = 1;
			ok &= (i - 1 > -1 && ans <= sqrtl(R[i - 1])) || !i;
			ok &= (i < N && ans >= sqrt(R[i])) || i == N;
			if(ok)
			{
				cout << ans;
				return 0;
			}
		}
		x = 2 * R[i] - x;
	}

	return 0;
}
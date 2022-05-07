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
	ll n, digit = 0, ds = 0, ans = INF64; cin >> n;
	vector<ll> d;
	while(n)
	{
		digit++;
		d.push_back(n % 10);
		ds += n % 10;
		n /= 10;
	}
	for(ll mask = 0; mask < (1LL<<digit) - 1; mask++)
	{
		ll i = mask, cur = ds, j = 0, removed = 0;
		while(i)
		{
			if(i & 1)
			{
				cur -= d[j];
				removed++;
			}
			j++;
			i /= 2;
		}
		if(!(cur % 3)) ans = min(ans, removed);
	}
	cout << (ans == INF64 ? -1 : ans);

	return 0;
}
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
	// #ifndef ONLINE_JUDGE
	// freopen(".in.txt", "r", stdin);
	// freopen(".out.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--)
	{
		ll x, y; cin >> x >> y;
		x--; y--;
		if(x >= y)
		{
			ll l = x/2, r = x/2 + (x & 1);
			cout << l + r * (4 * r - 1) + 1 + (x & 1 ? -1 : 1) * y << endl;
		}
		else
		{
			ll l = y/2, r = y/2 + (y & 1);
			cout << r + l * (4 * l + 3) + 1 + (y & 1 ? 1 : -1) * x << endl;
		}
	}

	return 0;
}
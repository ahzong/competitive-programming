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
	int t; cin >> t;
	while(t--)
	{
		int k, x, y, a, b, mini; cin >> k >> x >> y >> a >> b;
		a = abs(x - a);
		b = abs(y - b);
		if(a < b) swap(a, b);
		if(a == 1 && !b) mini = 3;
		else if(a == 2 && b == 2) mini = 4;
		else mini = a - b - 2 * floor(1. * (a - 2 * b)/(3 + (2 * b <= a)));
		if(k < mini)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << ((mini & 1) == (k & 1) ? "YES" : "NO") << endl;
	}

	return 0;
}
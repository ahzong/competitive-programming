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
	int n; cin >> n;
	vector<int> d1(n), d2(n);
	for(int i = 0; i < n; i++)
	{
		ll x, y; cin >> x >> y;
		d1[i] = x + y;
		d2[i] = x - y;
	}
	sort(d1.begin(), d1.end());
	sort(d2.begin(), d2.end());
	cout << max(d1[n - 1] - d1[0], d2[n - 1] - d2[0]);

	return 0;
}

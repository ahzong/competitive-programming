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
	int a, b, x, y; cin >> a >> b >> x >> y;
	int ans = (a <= b ? INF32 : x + abs(a - b) * y);
	for(int i = 2 * abs(a - b) + (a <= b ? 1 : -1) * 1, j = 0; i > 0; i -= 2, j++)
		ans = min(ans, i * x + j * y);
	cout << ans;

	return 0;
}
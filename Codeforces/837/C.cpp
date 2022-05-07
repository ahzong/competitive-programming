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
	int n, a, b, ans = 0; cin >> n >> a >> b;
	vector<pii> xy(n);
	for(int i = 0; i < n; i++) cin >> xy[i].first >> xy[i].second;
	for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
	{
		int x1 = xy[i].first, y1 = xy[i].second, x2 = xy[j].first, y2 = xy[j].second;
		bool ok = x1 + x2 <= a && y1 <= b && y2 <= b;
		ok |= x1 + x2 <= b && y1 <= a && y2 <= a;
		ok |= x1 + y2 <= a && y1 <= b && x2 <= b;
		ok |= x1 + y2 <= b && y1 <= a && x2 <= a;
		ok |= y1 + x2 <= a && x1 <= b && y2 <= b;
		ok |= y1 + x2 <= b && x1 <= a && y2 <= a;
		ok |= y1 + y2 <= a && x1 <= b && x2 <= b;
		ok |= y1 + y2 <= b && x1 <= a && x2 <= a;
		if(ok) ans = max(ans, x1 * y1 + x2 * y2);
	}
	cout << ans;

	return 0;
}
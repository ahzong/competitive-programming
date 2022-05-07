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
	bool ok = 0;
	vector<pii> p(n);
	for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
	for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
		for(int k = j + 1; k < n; k++)
		{
			int x1 = p[i].first, y1 = p[i].second;
			int x2 = p[j].first, y2 = p[j].second;
			int x3 = p[k].first, y3 = p[k].second;
			ok |= (x2 - x1) * (y3 - y2) == (x3 - x2) * (y2 - y1);
		}
	cout << (ok ? "Yes" : "No");

	return 0;
}
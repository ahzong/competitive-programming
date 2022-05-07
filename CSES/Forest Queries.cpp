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
	int n, q; cin >> n >> q;
	vector<vector<int>> pfx(n + 1, vector<int> (n + 1));
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	{
		char c; cin >> c;
		pfx[i][j] = c == '*';
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
		pfx[i][j] += pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1];
	while(q--)
	{
		int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
		cout << pfx[y2][x2] - pfx[y2][x1 - 1] - pfx[y1 - 1][x2] + pfx[y1 - 1][x1 - 1] << endl;
	}

	return 0;
}
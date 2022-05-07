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
	int n, m, x1, x2, y1, y2; cin >> n >> m;
	char c; cin >> c;
	set<char> s;
	vector<string> grid(n);
	for(int i = 0; i < n; i++) cin >> grid[i];
	for(int i = 0; i < n; i++) 
	{
		bool ok = 0;
		for(int j = 0; j < m; j++) if(grid[i][j] == c)
		{
			ok = 1;
			x1 = i;
			y1 = j;
			break;
		}
		if(ok) break;
	}
	
	for(int i = n - 1; i > -1; i--)
	{
		bool ok = 0;
		for(int j = m - 1; j > -1; j--) if(grid[i][j] == c)
		{
			ok = 1;
			x2 = i;
			y2 = j;
			break;
		}
		if(ok) break;
	}
	
	for(int i = x1; i <= x2; i++) for(int j = y1; j <= y2; j++)
	{
		if(i && grid[i - 1][j] != '.') s.insert(grid[i - 1][j]);
		if(j && grid[i][j - 1] != '.') s.insert(grid[i][j - 1]);
		if(i < n - 1 && grid[i + 1][j] != '.') s.insert(grid[i + 1][j]);
		if(j < m - 1 && grid[i][j + 1] != '.') s.insert(grid[i][j + 1]);
	}
	cout << (s.count(c) ? s.size() - 1 : s.size());

	return 0;
}
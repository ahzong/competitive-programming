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
	int n, m, d, ans = 0; cin >> n >> m >> d;
	queue<pii> bfs;
	vector<vector<int>> grid(n, vector<int> (m));
	vector<vector<bool>> visited(n, vector<bool> (m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];
	bfs.push(make_pair(0, 0));
	visited[0][0] = 1;
	while(!bfs.empty())
	{
		int i = bfs.front().first, j = bfs.front().second; bfs.pop();
		ans++;
		visited[i][j] = 1;
		if(i && !visited[i - 1][j] && abs(grid[i][j] - grid[i - 1][j]) < d)
		{
			visited[i - 1][j] = 1;
			bfs.push(make_pair(i - 1, j));
		}
		if(j && !visited[i][j - 1] && abs(grid[i][j] - grid[i][j - 1]) < d)
		{
			visited[i][j - 1] = 1;
			bfs.push(make_pair(i, j - 1));
		}
		if(i < n - 1 && !visited[i + 1][j] && abs(grid[i][j] - grid[i + 1][j]) < d)
		{
			visited[i + 1][j] = 1;
			bfs.push(make_pair(i + 1, j));
		}
		if(j < m - 1 && !visited[i][j + 1] && abs(grid[i][j] - grid[i][j + 1]) < d)
		{
			visited[i][j + 1] = 1;
			bfs.push(make_pair(i, j + 1));
		}
	}
	cout << ans;

	return 0;
}
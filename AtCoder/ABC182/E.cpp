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
	int h, w, n, m, ans = 0; cin >> h >> w >> n >> m;
	vector<vector<int>> grid(h, vector<int> (w, -1));
	// -1 means dark but not block
	// 0 means block
	// 1 means bulb
	// 2 means light
	for(int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		grid[a][b] = 1;
	}
	for(int i = 0; i < m; i++)
	{
		int c, d; cin >> c >> d;
		c--; d--;
		grid[c][d] = 0;
	}
	for(int r = 0; r < h; r++)
	{
		bool light = 0;
		for(int i = -1, j = 0; ; j++)
		{
			while(j < w && grid[r][j] == -1)
			{
				if(light) grid[r][j] = 2;
				j++;
			}
			if(j == w) break;
			if(!grid[r][j])
			{
				light = 0;
				i = j;
			}
			else if(grid[r][j] == 1 && !light)
			{
				light = 1;
				for(int k = i + 1; k < j; k++) grid[r][k] = 2;
			}
		}
	}
	for(int c = 0; c < w; c++)
	{
		bool light = 0;
		for(int i = -1, j = 0; ; j++)
		{
			while(j < h && grid[j][c] == -1)
			{
				if(light) grid[j][c] = 2;
				j++;
			}
			if(j == h) break;
			if(!grid[j][c])
			{
				light = 0;
				i = j;
			}
			else if(grid[j][c] == 1 && !light)
			{
				light = 1;
				for(int k = i + 1; k < j; k++) grid[k][c] = 2;
			}
		}
	}
	for(vector<int> x : grid) for(int y : x) ans += y > 0;
	cout << ans;

	return 0;
}
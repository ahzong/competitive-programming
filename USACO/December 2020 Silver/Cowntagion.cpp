#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ans = 0;
vector<vector<int>> adj;

void dfs(int v, int p)
{
	int c = adj[v].size() - (v > 0);
	ans += c;
	for(int i = 1; i < c + 1; i *= 2) ans++;
	for(int x : adj[v]) if(x != p) dfs(x, v);
}

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen(".in.txt", "r", stdin);
	// freopen(".out.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	adj.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	cout << ans << endl;

	return 0;
}
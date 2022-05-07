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

bool ok = 1;
vector<vector<int>> adj;
vector<int> p;
vector<int> h;
vector<int> g;
vector<int> a;

void dfs(int v, int prev)
{
	int sg = 0;
	a[v] = p[v];
	for(int i = 0; i < adj[v].size(); i++) if(adj[v][i] != prev)
	{
		dfs(adj[v][i], v);
		if(!ok) return;
		a[v] += a[adj[v][i]];
		sg += g[adj[v][i]];
	}
	g[v] = (a[v] + h[v])/2;
	if(((a[v] + h[v]) & 1) || g[v] < 0 || a[v] - g[v] < 0 || sg > g[v])
	{
		ok = 0;
		return;
	}
}

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
		int n, m; cin >> n >> m;
		adj.resize(n);
		p.resize(n);
		h.resize(n);
		g.resize(n);
		a.resize(n);
		for(int i = 0; i < n; i++) cin >> p[i];
		for(int i = 0; i < n; i++) cin >> h[i];
		for(int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0, -1);
		cout << (ok ? "YES" : "NO") << endl;
		ok = 1;
		adj.clear();
		g.clear();
		a.clear();
	}

	return 0;
}
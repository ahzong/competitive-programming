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

int head = -1;
bool incycle = 0;
vector<ll> sz;
vector<int> cycle;
vector<bool> visited;
vector<vector<int>> adj;

void dfs1(int v, int p)
{
	visited[v] = 1;
	for(int x : adj[v]) if(x != p)
	{
		if(visited[x])
		{
			head = x;
			incycle = 1;
			cycle.push_back(v);
			return;
		}
		dfs1(x, v);
		if(incycle)
		{
			cycle.push_back(v);
			if(v == head) incycle = 0;
			return;
		}
	}
}

ll dfs2(int v, int p)
{
	ll ret = 0;
	for(int x : adj[v]) if(x != p) ret += dfs2(x, v);
	return ret + 1;
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
		ll n, ans = 0; cin >> n;
		adj.resize(n);
		visited.resize(n);
		for(ll i = 0; i < n; i++)
		{
			int u, v; cin >> u >> v;
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs1(0, -1);
		int k = cycle.size();
		sz.resize(k);
		for(int i = 0; i < k; i++)
		{
			int adj1 = cycle[i ? i - 1 : k - 1], adj2 = cycle[i < k - 1 ? i + 1 : 0];
			for(int x : adj[cycle[i]]) if(x != adj1 && x != adj2) sz[i] += dfs2(x, cycle[i]);
			sz[i]++;
			ans += (sz[i] * (sz[i] - 1))/2 + sz[i] * (n - sz[i]);
		}
		cout << ans << endl;
		head = -1;
		incycle = 0;
		sz.clear();
		cycle.clear();
		visited.clear();
		adj.clear();
	}

	return 0;
}
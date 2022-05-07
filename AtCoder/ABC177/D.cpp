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

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> assigned;
vector<int> sz;
int c = 1;

void dfs1(int v)
{
  	visited[v] = 1;
  	for(int i = 0; i < adj[v].size(); i++) if(!visited[adj[v][i]])
    {
      	c++;
      	dfs1(adj[v][i]);
    }
}
 
void dfs2(int v)
{
  	sz[v] = c;
  	assigned[v] = 1;
  	for(int i = 0; i < adj[v].size(); i++) if(!assigned[adj[v][i]]) dfs2(adj[v][i]);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	adj.resize(n);
	visited.resize(n);
	assigned.resize(n);
	sz.resize(n);
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < n; i++) if(!visited[i])
	{
		dfs1(i);
		dfs2(i);
		c = 1;
	}
	cout << *max_element(sz.begin(), sz.end());

	return 0;
}
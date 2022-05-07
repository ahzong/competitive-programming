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

int ans1;
vector<int> dp;
vector<vector<pair<int, bool>>> adj;

void dfs1(int v, int p)
{
	for(pair<int, bool> x : adj[v]) if(x.first != p)
	{
		dp[0] += x.second;
		dfs1(x.first, v);
	}
}

void dfs2(int v, int p)
{
	for(pair<int, bool> x : adj[v]) if(x.first == p)
	{
		dp[v] = dp[p] + (x.second ? 1 : -1);
		ans1 = min(ans1, dp[v]);
	}
	for(pair<int, bool> x : adj[v]) if(x.first != p) dfs2(x.first, v);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	dp.resize(n);
	adj.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		// 1 means inverted direction
		adj[u].push_back(make_pair(v, 0));
		adj[v].push_back(make_pair(u, 1));
	}
	dfs1(0, -1);
	ans1 = dp[0];
	dfs2(0, -1);
	cout << ans1 << endl;
	for(int i = 0; i < n; i++) if(dp[i] == ans1) cout << i + 1 << ' ';

	return 0;
}
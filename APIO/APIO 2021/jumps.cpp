#include "jumps.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF64 = 1LL<<60;

ll n;
vector<ll> h;
vector<vector<ll>> dist;
vector<vector<ll>> adj;

void f(int u)
{
	queue<pair<ll, ll>> bfs;
	vector<bool> visited(n);
	bfs.push(make_pair(u, 0));
	visited[u] = 1;
	while(!bfs.empty())
	{
		int curv = bfs.front().first, curd = bfs.front().second; bfs.pop();
		dist[u][curv] = curd;
		for(auto x : adj[curv]) if(!visited[x])
		{
			bfs.push(make_pair(x, curd + 1));
			visited[x] = 1;
		}
	}
}

void init(int N, vector<int> H) {
	n = N;
	h.resize(n);
	dist.resize(n);
	adj.resize(n);
	for(int i = 0; i < n; i++)
	{
		h[i] = H[i];
		dist[i].resize(n);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = i - 1; j > -1; j--) if(h[j] > h[i])
		{
			adj[i].push_back(j);
			break;
		}
		for(int j = i + 1; j < n; j++) if(h[j] > h[i])
		{
			adj[i].push_back(j);
			break;
		}
	}
	for(int i = 0; i < n; i++) f(i);
}

int minimum_jumps(int A, int B, int C, int D) {
	ll ans = INF64;
	ll a = A, b = B, c = C, d = D;

	for(int i = a; i <= b; i++) for(int j = c; j <= d; j++)
		if(dist[i][j] > 0) ans = min(ans, dist[i][j]);

  	return (ans == INF64 ? -1 : ans);
}
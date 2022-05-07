#include "roads.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> minimum_closure_costs(int N, vector<int> U, vector<int> V, vector<int> W) {
	ll n = N;
	vector<ll> u(n - 1), v(n - 1), w(n - 1);
	for(int i = 0; i < n - 1; i++)
	{
		u[i] = U[i];
		v[i] = V[i];
		w[i] = W[i];
	}

	vector<ll> ans(n);
	vector<vector<ll>> dp(n - 1, vector<ll> (2));
	dp[0][0] = w[0];
	for(int i = 0; i < n - 1; i++) ans[0] += w[i];
	for(int i = 1; i < n - 1; i++)
	{
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
		if(i > 1) dp[i][0] = min(dp[i][0], dp[i - 2][0]);
		dp[i][0] += w[i];
		dp[i][1] = dp[i - 1][0];
	}
	ans[1] = min(dp[n - 2][0], dp[n - 2][1]);

	return ans;
}
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 998244353;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}

ll sub(ll a, ll b)
{
	return ((a - b) % MOD + MOD) % MOD;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k; cin >> n >> k;
	vector<ll> dp(n + 1);
	vector<ll> pre(n + 1);
	vector<bool> canuse(n + 1, 0);
	vector<pair<ll, ll>> seg;
	dp[1] = pre[1] = 1;
	for(ll i = 0; i < k; i++)
	{
		ll l, r; cin >> l >> r;
		for(ll j = l; j <= r; j++) canuse[j] = 1;
	}
	for(ll i = 1; i <= n; i++) if(canuse[i])
	{
		seg.push_back(make_pair(i, -1));
		while(i <= n && canuse[i]) i++;
		seg[seg.size() - 1].second = i - 1;
	}
	for(ll i = 2; i <= n; i++) for(pii x : seg)
	{
		ll l = max(1LL, i - x.second), r = max(0LL, i - x.first);
		dp[i] = add(dp[i], sub(pre[r], pre[l - 1]));
		pre[i] = pre[i - 1] + dp[i];
	}
	cout << dp[n];

	return 0;
}

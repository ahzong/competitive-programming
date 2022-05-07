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
	ll n, sumodd = 0, sumeven = 1; cin >> n;
	vector<ll> dp(n, 1);
	for(ll i = 1; i < n; i++)
	{
		dp[i] = (dp[i] + (i & 1 ? sumeven : sumodd)) % MOD;
		if(i & 1) sumodd = (sumodd + dp[i]) % MOD;
		else sumeven = (sumeven + dp[i]) % MOD;
	}
	cout << (sumodd + sumeven) % MOD;

	return 0;
}
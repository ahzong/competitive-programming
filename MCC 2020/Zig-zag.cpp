#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e3;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

ll dp[20000][101][2];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	int k, n = s.size(); cin >> k;
	ll ans = 0;
	if(k == 1)
	{
		cout << n % MOD;
		return 0;
	}
	for(int i = 0; i < n; i++) dp[i][1][0] = dp[i][1][1] = 1;
	for(int i = 0; i < n; i++) for(int j = 2; j <= min(k, i + 1); j++)
		for(int x = 0; x < i; x++)
		{
			if(s[x] > s[i]) dp[i][j][0] = (dp[i][j][0] + dp[x][j - 1][1]) % MOD;
			else if(s[x] < s[i]) dp[i][j][1] = (dp[i][j][1] + dp[x][j - 1][0]) % MOD;
		}
	for(int i = 0; i < n; i++) ans = (ans + (dp[i][k][0] + dp[i][k][1]) % MOD) % MOD;
	cout << ans;

	return 0;
}
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

ld dp[101][101][101];

ld f(int a, int b, int c, int x)
{
	if(a == 100 || b == 100 || c == 100) return x;
	if(dp[a][b][c]) return dp[a][b][c];
	if(a) dp[a][b][c] += 1.0 * a/(a + b + c) * f(a + 1, b, c, x + 1);
	if(b) dp[a][b][c] += 1.0 * b/(a + b + c) * f(a, b + 1, c, x + 1);
	if(c) dp[a][b][c] += 1.0 * c/(a + b + c) * f(a, b, c + 1, x + 1);
	return dp[a][b][c];
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(20) << fixed;
	int a, b, c; cin >> a >> b >> c;
	cout << f(a, b, c, 0);

	return 0;
}
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
	int l; cin >> l;
	vector<vector<ll>> c(l, vector<ll> (l));
	c[0][0] = c[1][0] = c[1][1] = 1;
	for(int i = 2; i < l; i++) for(int j = 0; j <= i; j++)
	{
		if(!j || j == i) c[i][j] = 1;
		else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	cout << c[l - 1][11];

	return 0;
}
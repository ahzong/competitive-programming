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
	int t; cin >> t;
	while(t--)
	{
		int n, m, mini = INF32, cn = 0, s = 0; cin >> n >> m;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
		{
			int a; cin >> a;
			cn += a < 0;
			a = abs(a);
			mini = min(mini, a);
			s += a;
		}
		cout << s - (cn & 1) * 2 * mini << endl;
	}

	return 0;
}
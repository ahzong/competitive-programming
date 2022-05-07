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
		int n, k, j = 1; cin >> n >> k;
		vector<string> ans(n, string(n, '0'));
		cout << (k % n ? 2 : 0) << endl;
		for(int i = 0; k; i++, j++)
		{
			if(!(i % n)) j--;
			ans[i % n][j % n] = '1';
			k--;
		}
		for(int i = 0; i < n; i++) cout << ans[i] << endl;
	}

	return 0;
}
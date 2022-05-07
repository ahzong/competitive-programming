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
	int n, ans = 0; cin >> n;
	vector<int> prefixh(n + 1), prefixp(n + 1), prefixs(n + 1);
	for(int i = 1; i <= n; i++)
	{
		char gesture; cin >> gesture;
		prefixh[i] = prefixh[i - 1] + (gesture == 'H');
		prefixp[i] = prefixp[i - 1] + (gesture == 'P');
		prefixs[i] = prefixs[i - 1] + (gesture == 'S');
	}
	for(int i = 0; i <= n; i++)
	{
		ans = max(ans, prefixs[i] + prefixh[n] - prefixh[i]);
		ans = max(ans, prefixh[i] + prefixs[n] - prefixs[i]);
		ans = max(ans, prefixs[i] + prefixp[n] - prefixp[i]);
		ans = max(ans, prefixp[i] + prefixs[n] - prefixs[i]);
		ans = max(ans, prefixh[i] + prefixp[n] - prefixp[i]);
		ans = max(ans, prefixp[i] + prefixh[n] - prefixh[i]);
	}
	cout << ans;

	return 0;
}
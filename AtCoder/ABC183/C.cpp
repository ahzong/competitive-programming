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
	ll n, k, ans = 0; cin >> n >> k;
	vector<int> p(n);
	vector<vector<ll>> t(n, vector<ll> (n));
	for(int i = 1; i < n; i++) p[i] = i;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> t[i][j];
	do
	{
		if(p[0]) continue;
		ll cur = 0;
		for(int i = 1; i < n; i++) cur += t[p[i - 1]][p[i]];
		ans += cur + t[p[n - 1]][0] == k;
	} while(next_permutation(p.begin(), p.end()));
	cout << ans;

	return 0;
}
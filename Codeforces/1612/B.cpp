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
		int n, a, b; cin >> n >> a >> b;
		a--; b--;
		vector<ll> ans(n);
		vector<bool> used(n);
		ans[0] = a;
		used[a] = 1;
		ans[n/2] = b;
		used[b] = 1;
		for(int i = 1, j = n - 1; i < n/2; i++)
		{
			while(used[j]) j--;
			ans[i] = j;
			used[j] = 1;
		}
		for(int i = n/2 + 1, j = 0; i < n; i++)
		{
			while(used[j]) j++;
			ans[i] = j;
			used[j] = 1;
		}
		ll mini = n + 1, maxi = -1;
		for(int i = 0; i < n/2; i++) mini = min(mini, ans[i]);
		for(int i = n/2; i < n; i++) maxi = max(maxi, ans[i]);
		if(mini != a || maxi != b)
		{
			cout << -1 << endl;
			continue;
		}
		for(ll x : ans) cout << x + 1 << ' ';
		cout << endl;
	}

	return 0;
}
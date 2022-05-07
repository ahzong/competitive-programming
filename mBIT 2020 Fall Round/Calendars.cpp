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
	ll n, r = 0, cur = 0, j = 0; cin >> n;
	vector<int> b(n);
	vector<ll> ind(n);
	vector<pair<ll, int>> pass;
	for(ll i = 0; i < n; i++)
	{
		int a; cin >> a;
		a--;
		ind[a] = i;
	}
	for(ll i = 0; i < n; i++)
	{
		cin >> b[i];
		b[i]--;
		if(i < ind[b[i]]) r++;
		cur += abs(ind[b[i]] - i);
		pass.push_back(make_pair(i < ind[b[i]] ? i + n - ind[b[i]] : i - ind[b[i]], b[i]));
	}
	ll ans = cur;
	sort(pass.begin(), pass.end());
	for(ll i = 0; i < n - 1; i++)
	{
		r--;
		while(j < n && pass[j].first == i)
		{
			r++;
			j++;
		}
		cur += 2 * (r - ind[b[i]]);
		ans = min(ans, cur);
	}
	cout << ans;

	return 0;
}
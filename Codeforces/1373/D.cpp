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
		int n; cin >> n;
		ll cur = 0, maxi = 0, ans = 0;
		vector<ll> a(n);
		vector<ll> v1(n/2);
		vector<ll> v2(n/2 - (!(n & 1)));
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(!(i & 1)) ans += a[i];
		}
		for(int i = 1; i < n; i += 2)
		{
			v1[(i - 1)/2] = a[i] - a[i - 1];
			if(i < n - 1) v2[(i - 1)/2] = a[i] - a[i + 1];
		}
		for(int i = 0; i < n/2; i++)
		{
			cur = max(v1[i], v1[i] + cur);
			maxi = max(maxi, cur);
		}
		cur = 0;
		for(int i = 0; i < n/2 - (!(n & 1)); i++)
		{
			cur = max(v2[i], v2[i] + cur);
			maxi = max(maxi, cur);
		}
		cout << ans + maxi << endl;
	}

	return 0;
}
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

struct x
{
	ll val, index, coord;
	bool operator< (const x &rhs) const
	{
		return val > rhs.val;
	}
};

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
		ll ans = 0;
		int n; cin >> n;
		vector<x> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i].val;
			a[i].index = i;
		}
		sort(a.begin(), a.end());
		for(ll i = 0, d = 0; i < n; i++)
		{
			if(!(i & 1)) d++;
			a[i].coord = (i & 1) ? -d : d;
			ans += d * a[i].val;
		}
		cout << ans * 2 << endl << 0 << ' ';
		vector<ll> coords(n);
		for(int i = 0; i < n; i++) coords[a[i].index] = a[i].coord;
		for(ll y : coords) cout << y << ' ';
		cout << endl;
	}

	return 0;
}
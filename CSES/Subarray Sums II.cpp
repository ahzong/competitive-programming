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
	// #ifndef ONLINE_JUDGE
	// freopen(".in.txt", "r", stdin);
	// freopen(".out.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	ll x, ans = 0; cin >> x;
	vector<ll> psum(n + 1);
	map<ll, ll> mapp;
	mapp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		ll a; cin >> a;
		psum[i] = psum[i - 1] + a;
		mapp[psum[i]]++;
	}
	for(int i = 0; i <= n; i++)
	{
		mapp[psum[i]]--;
		ans += mapp[x + psum[i]];
	}
	cout << ans;

	return 0;
}
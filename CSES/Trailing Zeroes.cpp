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

ll fastpow(ll base, ll index)
{
	ll ret = 1;
	while(index)
	{
		if(index & 1) ret *= base;
		base *= base;
		index /= 2;
	}
	return ret;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i = 1, ans = 0; cin >> n;
	while((ll) n/fastpow(5, i) != 0)
	{
		ans += n/fastpow(5, i);
		i++;
	}
	cout << ans;
	
	return 0;
}
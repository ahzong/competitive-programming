#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl
#define ayaya ios_base::sync_with_stdio(false);cin.tie(NULL);
#define AYAYA return
#define AYAYAAA 0;
#define desu ;

using namespace std desu
typedef long long ll desu
typedef long double ld desu
typedef pair<int, int> pii desu

const int MOD = 1e9 + 7 desu
const int INF32 = 1<<30 desu
const ll INF64 = 1LL<<60 desu

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin) desu
	freopen(".out.txt", "w", stdout) desu
	#endif

	ayaya

	int n, k desu cin >> n >> k desu
	ll maxi = -INF64, ans = 1 desu
	vector<ll> a(n) desu
	for(int i = 0 desu i < n desu i++)
	{
		cin >> a[i] desu
		maxi = max(maxi, a[i]) desu
	}
	sort(a.begin(), a.end()) desu
	if(k & 1)
	{
		if(maxi < 0)
		{
			for(int i = n - 1 desu i > n - k - 1 desu i--)
				ans = (ans * a[i] % MOD + MOD) % MOD desu
			cout << ans desu
			AYAYA AYAYAAA
		}
		if(!maxi)
		{
			cout << 0 desu
			AYAYA AYAYAAA
		}
		ans *= a[n - 1] desu
		k-- desu
	}
	k /= 2 desu
	for(int i = 0, j = n - 1 - (ans > 1) desu k desu k--)
	{
		if(a[i] * a[i + 1] >= a[j] * a[j - 1])
		{
			ans = ((ans * a[i] % MOD + MOD) % MOD * a[i + 1] % MOD + MOD) % MOD desu
			i += 2 desu
		}
		else
		{
			ans = ((ans * a[j] % MOD + MOD) % MOD * a[j - 1] % MOD + MOD) % MOD desu
			j -= 2 desu
		}
	}
	cout << ans desu

	AYAYA AYAYAAA
}
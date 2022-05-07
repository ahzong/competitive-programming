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
		int maxi = 0;
		map<ll, int> pf;
		ll n, maxinum; cin >> n;
		ll nn = n;
		if(n == 2)
		{
			cout << 1 << endl << 2 << endl;
			continue;
		}
		while(!(n & 1))
		{
			pf[2]++;
			if(pf[2] > maxi)
			{
				maxi = pf[2];
				maxinum = 2;
			}
			n /= 2;
		}
		for(ll i = 3; i * i <= n; i += 2) while(!(n % i))
		{
			pf[i]++;
			if(pf[i] > maxi)
			{
				maxi = pf[i];
				maxinum = i;
			}
			n /= i;
		}
		if(n > 2)
		{
			pf[n]++;
			if(pf[n] > maxi)
			{
				maxi = pf[n];
				maxinum = n;
			}
			n = 1;
		}
		// for(auto x : pf) cout << x.first << ' ' << x.second << endl;
		cout << maxi << endl;
		if(maxi == 1)
		{
			cout << nn << endl;
			continue;
		}
		for(int i = 0; i < maxi - 1; i++)
		{
			cout << maxinum << ' ';
			nn /= maxinum;
		}
		cout << nn << endl;
	}

	return 0;
}
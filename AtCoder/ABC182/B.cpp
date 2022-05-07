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
	int n, ans, maxi = 0; cin >> n;
	map<int, int> freq;
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a;
		freq[a]++;
		if(freq[a] > maxi)
		{
			ans = a;
			maxi = freq[a];
		}
		for(int j = 2; j * j <= a; j++) if(!(a % j))
		{
			freq[j]++;
			if(a/j != j) freq[a/j]++;
			if(freq[j] > maxi)
			{
				maxi = freq[j];
				ans = j;
			}
			if(freq[a/j] > maxi)
			{
				maxi = freq[a/j];
				ans = a/j;
			}
		}
	}
	cout << ans;

	return 0;
}
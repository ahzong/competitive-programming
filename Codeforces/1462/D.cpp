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
		int n, s = 0; cin >> n;
		int maxi = 1;
		vector<int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			s += a[i];
		}
		for(int i = 1; i * i <= s; i++) if(!(s % i))
		{
			int cur1 = 0, cur2 = 0, c1 = 0, c2 = 0;
			bool ok1 = 1, ok2 = 1;
			for(int j = 0; j < n; j++)
			{
				cur1 += a[j];
				cur2 += a[j];
				ok1 &= cur1 <= s/i;
				ok2 &= cur2 <= i;
				if(cur1 == s/i)
				{
					cur1 = 0;
					c1++;
				}
				if(cur2 == i)
				{
					cur2 = 0;
					c2++;
				}
			}
			if(ok1 && c1 == i) maxi = max(maxi, i);
			if(ok2 && c2 == s/i) maxi = max(maxi, s/i);
		}
		cout << n - maxi << endl;
	}

	return 0;
}
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
		int n, m; cin >> n >> m;
		bool ok = 1;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
		{
			int a; cin >> a;
			if((!i || i == n - 1) && (!j || j == m - 1) && a > 2) ok = 0;
			else if((!i || i == n - 1 || !j || j == m - 1) && a > 3) ok = 0;
			else if(a > 4) ok = 0;
		}
		if(!ok)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if((!i || i == n - 1) && (!j || j == m - 1)) cout << 2 << ' ';
				else if(!i || i == n - 1 || !j || j == m - 1) cout << 3 << ' ';
				else cout << 4 << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}
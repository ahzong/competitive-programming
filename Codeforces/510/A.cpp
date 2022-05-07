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
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		if(i & 1) for(int j = 0; j < m; j++) cout << '#';
		else
		{
			if(i % 4 == 0)
			{
				cout << '#';
				for(int j = 1; j < m; j++) cout << '.';
			}
			else
			{
				for(int j = 0; j < m - 1; j++) cout << '.';
				cout << '#';
			}
		}
		cout << endl;
	}

	return 0;
}
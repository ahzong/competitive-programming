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
		int x; cin >> x;
		if(x > 45)
		{
			cout << -1 << endl;
			continue;
		}
		int s = 0, i = 9;
		while(i && s + i <= x)
		{
			s += i;
			i--;
		}
		if(x - s) cout << x - s;
		for(int j = i + 1; j <= 9; j++) cout << j;
		cout << endl;
	}

	return 0;
}
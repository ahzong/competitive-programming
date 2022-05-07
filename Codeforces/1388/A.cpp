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
		int n; cin >> n;
		if(n < 31) cout << "NO" << endl;
		else if(n == 36)
			cout << "YES" << endl << 6 << ' ' << 14 << ' ' << 15 << ' ' << 1 << endl;
		else if(n == 40)
			cout << "YES" << endl << 10 << ' ' << 14 << ' ' << 15 << ' ' << 1 << endl;
		else if(n == 44)
			cout << "YES" << endl << 10 << ' ' << 14 << ' ' << 15 << ' ' << 5 << endl;
		else cout << "YES" << endl << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << endl;
	}

	return 0;
}
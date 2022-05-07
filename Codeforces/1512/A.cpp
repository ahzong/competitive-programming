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
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		if(a[0] != a[1])
			cout << (a[0] == a[2] ? 2 : 1) << endl;
		else if(a[n - 2] != a[n - 1])
			cout << (a[n - 1] == a[n - 3] ? n - 1 : n) << endl;
		else
		{
			for(int i = 1; i < n - 1; i++) if(a[i] != a[i - 1] && a[i] != a[i + 1])
				cout << i + 1 << endl;
		}
	}

	return 0;
}
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
	int n, ce = 0, co = 0, le, lo; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if(a & 1)
		{
			co++;
			lo = i;
		}
		else
		{
			ce++;
			le = i;
		}
	}
	cout << (co == 1 ? lo + 1 : le + 1);

	return 0;
}
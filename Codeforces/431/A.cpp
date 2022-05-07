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
	int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
	int ans = 0;
	string s; cin >> s;
	for(char c : s)
	{
		if(c == '1') ans += a1;
		else if(c == '2') ans += a2;
		else if(c == '3') ans += a3;
		else ans += a4;
	}
	cout << ans;

	return 0;
}
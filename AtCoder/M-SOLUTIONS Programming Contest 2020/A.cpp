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
	int x; cin >> x;
	if(x >= 400 && x <= 599) cout << 8;
	else if(x >= 600 && x <= 799) cout << 7;
	else if(x >= 800 && x <= 999) cout << 6;
	else if(x >= 1000 && x <= 1199) cout << 5;
	else if(x >= 1200 && x <= 1399) cout << 4;
	else if(x >= 1400 && x <= 1599) cout << 3;
	else if(x >= 1600 && x <= 1799) cout << 2;
	else cout << 1;

	return 0;
}
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
	// #ifndef ONLINE_JUDGE
	// freopen(".in.txt", "r", stdin);
	// freopen(".out.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a1, b1, a2, b2, c1, d1, c2, d2, g = 0, e = 0;
	cin >> a1 >> b1 >> a2 >> b2 >> c1 >> d1 >> c2 >> d2;
	for(int i = a1; i <= b1; i++) for(int j = a2; j <= b2; j++) for(int k = c1; k <= d1; k++)
		for(int l = c2; l <= d2; l++) if(i + j != k + l)
		{
			if(i + j > k + l) g++;
			else e++;
		}
	if(g > e) cout << "Gunnar";
	else if(g < e) cout << "Emma";
	else cout << "Tie";

	return 0;
}
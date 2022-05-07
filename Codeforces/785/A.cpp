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
	map<string, int> mapp;
	mapp["Tetrahedron"] = 4;
	mapp["Cube"] = 6;
	mapp["Octahedron"] = 8;
	mapp["Dodecahedron"] = 12;
	mapp["Icosahedron"] = 20;
	int n, ans = 0; cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		ans += mapp[s];
	}
	cout << ans;

	return 0;
}
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

const string rgb = "RGB";

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
		int n, k, ans = INF32; cin >> n >> k;
		string s; cin >> s;
		for(int i = 0; i <= s.size() - k; i++)
		{
			int c1 = 0, c2 = 0, c3 = 0, r = 0, g = 1, b = 2;
			string t = s.substr(i, k);
			for(char c : t)
			{
				c1 += c != rgb[r % 3];
				c2 += c != rgb[g % 3];
				c3 += c != rgb[b % 3];
				r++;
				g++;
				b++;
			}
			ans = min({ans, c1, c2, c3});
		}
		cout << ans << endl;
	}

	return 0;
}
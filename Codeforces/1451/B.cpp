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
		int n, q; cin >> n >> q;
		string s; cin >> s;
		while(q--)
		{
			int l, r; cin >> l >> r;
			bool ok = 0;
			l--; r--;
			for(int i = l - 1; i > -1; i--) if(s[i] == s[l])
			{
				cout << "YES" << endl;
				ok = 1;
				break;
			}
			if(ok) continue;
			for(int i = r + 1; i < n; i++) if(s[i] == s[r])
			{
				cout << "YES" << endl;
				ok = 1;
				break;
			}
			if(!ok) cout << "NO" << endl;
		}
	}

	return 0;
}
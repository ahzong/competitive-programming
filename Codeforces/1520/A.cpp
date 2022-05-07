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
		bool ok = 1;
		vector<bool> seen(26);
		string s; cin >> s;
		seen[s[0] - 'A'] = 1;
		for(int i = 1; i < n; i++) if(s[i] != s[i - 1])
		{
			if(!seen[s[i] - 'A']) seen[s[i] - 'A'] = 1;
			else
			{
				cout << "NO" << endl;
				ok = 0;
				break;
			}
		}
		if(ok) cout << "YES" << endl;
	}

	return 0;
}
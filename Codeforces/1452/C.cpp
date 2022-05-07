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
		string s; cin >> s;
		int cr = 0, cb = 0, ans = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '(') cr++;
			else if(s[i] == ')' && cr)
			{
				ans++;
				cr--;
			}
			else if(s[i] == '[') cb++;
			else if(s[i] == ']' && cb)
			{
				ans++;
				cb--;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
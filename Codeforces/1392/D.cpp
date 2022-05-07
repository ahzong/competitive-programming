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
		string s; cin >> s;
		set<char> st;
		for(int i = 0; i < n; i++) st.insert(s[i]);
		if(st.size() == 1)
		{
			cout << (n + 2)/3 << endl;
			continue;
		}
		int ans = 0, c = 0, i = 0, j = n - 1;
		if(s[0] == s[n - 1])
		{
			while(s[i] == s[0])
			{
				c++;
				i++;
			}
			while(s[j] == s[0])
			{
				c++;
				j--;
			}
			ans += c/3;
		}
		while(i <= j)
		{
			int ii = i;
			c = 0;
			while(s[ii] == s[i])
			{
				c++;
				ii++;
			}
			ans += c/3;
			i = ii;
		}
		cout << ans << endl;
	}

	return 0;
}
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
	ll ans = 0;
	string s; cin >> s;
	vector<ll> freq(26);
	for(int i = 0; i < s.size(); i++)
	{
		freq[s[i] - 'a']++;
		ans = max(ans, max(freq[s[i] - 'a'], freq[s[i] - 'a'] * (freq[s[i] - 'a'] - 1)/2));
	}
	for(char c1 = 'a'; c1 <= 'z'; c1++) for(char c2 = 'a'; c2 <= 'z'; c2++) if(c1 != c2)
	{
		ll cur = 0, c = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == c1) cur++;
			if(s[i] == c2) c += cur;
		}
		ans = max(ans, c);
	}
	cout << ans;

	return 0;
}
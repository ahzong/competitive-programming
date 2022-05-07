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
	int n, k; cin >> n >> k;
	string s, ans = ""; cin >> s;
	for(int i = 0; i < n; i++)
	{
		if(!k) ans += s[i];
		else if(k >= max('z' - s[i], s[i] - 'a'))
		{
			k -= max('z' - s[i], s[i] - 'a');
			if('z' - s[i] >= s[i] - 'a') ans += 'z';
			else ans += 'a';
		}
		else
		{
			if(s[i] - k >= 'a') ans += (char) (s[i] - k);
			else ans += (char) (s[i] + k);
			k = 0;
		}
	}
	cout << (k ? "-1" : ans);

	return 0;
}
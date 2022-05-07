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
	string s, ans = ""; cin >> s;
	int i = 0;
	for(; i < s.size() && s[i] != '2'; i++) ans += s[i];
	for(int j = i; j < s.size(); j++) if(s[j] == '1') ans += s[j];
	sort(ans.begin(), ans.end());
	for(; i < s.size(); i++) if(s[i] != '1') ans += s[i];
	cout << ans;

	return 0;
}
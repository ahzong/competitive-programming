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
	int maxi = 0;
	string s, ans = "-1"; cin >> s;
	map<string, int> freq;
	for(int i = 0; i < s.size(); i++) for(int j = i; j < s.size(); j++)
	{
		 if(s[j] != '7' && s[j] != '4') break;
		 else freq[s.substr(i, j - i + 1)]++;
	}
	for(auto x : freq) if(x.second > maxi)
	{
		maxi = x.second;
		ans = x.first;
	}
	cout << ans;

	return 0;
}
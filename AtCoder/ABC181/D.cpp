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
	string s; cin >> s;
	map<int, int> freq;
	for(char c : s) freq[c - '0']++;
	for(int i = 8; i < 1000; i += 8)
	{
		if(i < 100 && s.size() > 2) continue;
		int ii = i;
		bool ok = 1;
		map<int, int> f;
		while(ii)
		{
			f[ii % 10]++;
			ii /= 10;
		}
		if(s.size() <= 2) ok &= freq == f;
		else for(auto x : f) ok &= freq[x.first] >= x.second;
		if(ok)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";

	return 0;
}
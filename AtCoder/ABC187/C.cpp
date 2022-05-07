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
	int n; cin >> n;
	set<string> s;
	map<string, int> freq;
	for(int i = 0; i < n; i++)
	{
		string t; cin >> t;
		s.insert(t);
	}
	for(string x : s)
	{
		string t = x.substr(x[0] == '!', x.size());
		freq[t]++;
		if(freq[t] == 2)
		{
			cout << t;
			return 0;
		}
	}
	cout << "satisfiable";

	return 0;
}
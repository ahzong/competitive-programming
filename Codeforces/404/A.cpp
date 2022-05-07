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
	set<char> s1;
	set<char> s2;
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		s1.insert(s[i]);
		s1.insert(s[n - i - 1]);
		for(int j = 0; j < n; j++) if(j != i && j != n - i - 1) s2.insert(s[j]); 
	}
	cout << (s1.size() > 1 || s2.size() > 1 || *s1.begin() == *s2.begin() ? "NO" : "YES");

	return 0;
}
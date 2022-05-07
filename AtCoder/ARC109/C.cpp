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
	string s; cin >> s;
	s += s;
	for(int i = 0; i < k; i++)
	{
		string t = "";
		for(int j = 0; j < 2 * n; j += 2)
		{
			if(s[j] == s[j + 1]) t += s[j];
			if(s[j] == 'R' && s[j + 1] == 'S') t += 'R';
			if(s[j] == 'S' && s[j + 1] == 'R') t += 'R';
			if(s[j] == 'P' && s[j + 1] == 'R') t += 'P';
			if(s[j] == 'R' && s[j + 1] == 'P') t += 'P';
			if(s[j] == 'S' && s[j + 1] == 'P') t += 'S';
			if(s[j] == 'P' && s[j + 1] == 'S') t += 'S';
		}
		s = t + t;
	}
	cout << s[0];

	return 0;
}
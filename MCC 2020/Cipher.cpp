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
	string s, a; cin >> s;
	int k; cin >> k >> a;
	vector<string> lift(26, string(30, '?'));
	for(int i = 0; i < 26; i++)
	{
		char b; cin >> b;
		lift[a[i] - 'a'][0] = b;
	}
	for(int i = 1; i < 30; i++) for(int j = 0; j < 26; j++)
		lift[j][i] = lift[lift[j][i - 1] - 'a'][i - 1];
	for(int i = 0; i < s.size(); i++)
	{
		int kk = k;
		for(int j = 0; kk; j++, kk /= 2) if(kk & 1) s[i] = lift[s[i] - 'a'][j];
	}
	cout << s;

	return 0;
}
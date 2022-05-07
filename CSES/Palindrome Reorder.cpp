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
	int oc = 0;
	string s; cin >> s;
	vector<int> freq(26);
	for(int i = 0; i < s.size(); i++) freq[s[i] - 'A']++;
	for(int i = 0; i < 26; i++) oc += (freq[i] & 1);
	if(oc > 1)
	{
		cout << "NO SOLUTION";
		return 0;
	}
	char c;
	int odd = -1;
	string ans = "";
	for(int i = 0; i < 26; i++)
	{
		if(freq[i] & 1)
		{
			c = i + 'A';
			odd = freq[i];
		}
		else for(int j = 0; j < freq[i]/2; j++) ans += i + 'A';
	}
	cout << ans;
	if(odd > -1) cout << string(odd, c);
	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}
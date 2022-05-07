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
	string s, t; cin >> s >> t;
	vector<int> freqs(26), freqt(26);
	for(int i = 0; i < n; i++)
	{
		freqs[s[i] - 'a']++;
		freqt[t[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++) if(freqs[i] != freqt[i])
	{
		cout << -1;
		return 0;
	}
	vector<int> ans;
	for(int i = 0; i < n; i++) if(s[i] != t[i]) 
		for(int j = i; j < n; j++) if(s[j] == t[i])
		{
			for(int k = j - 1; k > i - 1; k--)
			{
				ans.push_back(k + 1);
				swap(s[k], s[k + 1]);
			}
			break;
		}
	cout << ans.size() << endl;
	for(int x : ans) cout << x << ' ';

	return 0;
}
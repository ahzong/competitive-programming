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
	int t; cin >> t;
	while(t--)
	{
		int n, k; cin >> n >> k;
		string a, b; cin >> a >> b;
		bool ok = 1;
		vector<int> freqa(26), freqb(26);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int i = 0; i < n; i++)
		{
			if(a[i] > b[i])
			{
				cout << "No" << endl;
				ok = 0;
				break;
			}
			freqa[a[i] - 'a']++;
			freqb[b[i] - 'a']++;
		}
		if(!ok) continue;
		for(int i = 0; i < 26; i++) if(abs(freqa[i] - freqb[i]) % k)
		{
			cout << "No" << endl;
			ok = 0;
			break;
		}
		if(ok) cout << "Yes" << endl;
	}

	return 0;
}
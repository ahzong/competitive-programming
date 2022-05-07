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
		int n, win = -1; cin >> n;
		vector<int> a(n);
		vector<int> freq(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i]--;
			freq[a[i]]++;
		}
		for(int i = 0; i < n; i++) if(freq[i] == 1)
		{
			win = i;
			break;
		}
		if(win == -1)
		{
			cout << -1 << endl;
			continue;
		}
		for(int i = 0; i < n; i++) if(a[i] == win)
		{
			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}
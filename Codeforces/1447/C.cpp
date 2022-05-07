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
		int n; cin >> n;
		ll W, s = 0; cin >> W;
		bool ok = 0;
		vector<int> ans;
		vector<pair<ll, int>> w(n);
		for(int i = 0; i < n; i++)
		{
			cin >> w[i].first;
			w[i].second = i + 1;
		}
		for(int i = 0; i < n; i++) if(w[i].first >= (W + 1)/2 && w[i].first <= W)
		{
			cout << 1 << endl << i + 1 << endl;
			ok = 1;
			break;
		}
		if(ok) continue;
		sort(w.begin(), w.end());
		for(int i = 0; i < n && w[i].first <= W; i++)
		{
			s += w[i].first;
			ans.push_back(w[i].second);
			if(s >= (W + 1)/2)
			{
				cout << ans.size() << endl;
				for(int x : ans) cout << x << ' ';
				cout << endl;
				ok = 1;
				break;
			}
		}
		if(!ok) cout << -1 << endl;
	}

	return 0;
}
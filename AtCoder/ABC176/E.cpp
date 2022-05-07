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
	int h, w, m, maxr = 0, maxc = 0; cin >> h >> w >> m;
	vector<int> r(h);
	vector<int> c(w);
	set<pii> hw;
	vector<int> maxri;
	vector<int> maxci;
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		x--; y--;
		hw.insert(make_pair(x, y));
		r[x]++;
		c[y]++;
		maxr = max(maxr, r[x]);
		maxc = max(maxc, c[y]);
	}
	for(int i = 0; i < h; i++) if(r[i] == maxr) maxri.push_back(i);
	for(int i = 0; i < w; i++) if(c[i] == maxc) maxci.push_back(i);
	if((ll) maxri.size() * (ll) maxci.size() > 3e5)
	{
		cout << maxr + maxc;
		return 0;
	}
	bool ok = 1;
	for(int i = 0; i < maxri.size(); i++) for(int j = 0; j < maxci.size(); j++)
		if(!hw.count(make_pair(maxri[i], maxci[j])))
		{
			ok = 0;
			break;
		}
	cout << maxr + maxc - ok;

	return 0;
}
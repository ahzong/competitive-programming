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

int n, k, l;
vector<int> d;
bool done[102][101][2];

bool brute(int pos, int p, bool tide)
{
	if(pos == n + 1) return 1;
	done[pos][p][tide] = 1;
	bool ret = 0;
	if(tide)
	{
		if(p == k) // p drops
		{
			if(!done[pos][p - 1][0]) ret |= brute(pos, p - 1, 0); // stay
			if(d[pos + 1] + p - 1 <= l && !done[pos + 1][p - 1][0])
				ret |= brute(pos + 1, p - 1, 0); // go
		}
		else // p increases
		{
			if(d[pos] + p + 1 <= l && !done[pos][p + 1][1])
				ret |= brute(pos, p + 1, 1); // stay
			if(d[pos + 1] + p + 1 <= l && !done[pos + 1][p + 1][1])
				ret |= brute(pos + 1, p + 1, 1); // go
		}
	}
	else
	{
		if(!p) // p increases
		{
			if(d[pos] + p + 1 <= l && !done[pos][p + 1][1])
				ret |= brute(pos, p + 1, 1); // stay
			if(d[pos + 1] + p + 1 <= l && !done[pos + 1][p + 1][1])
				ret |= brute(pos + 1, p + 1, 1); // go
		}
		else // p drops
		{
			if(!done[pos][p - 1][0]) ret |= brute(pos, p - 1, 0); // stay
			if(d[pos + 1] + p - 1 <= l && !done[pos + 1][p - 1][0])
				ret |= brute(pos + 1, p - 1, 0); // go
		}
	}
	return ret;
}

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
		cin >> n >> k >> l;
		d.resize(n + 2);
		d[0] = d[n + 1] = -INF32;
		for(int i = 1; i <= n; i++) cin >> d[i];
		cout << (brute(0, 0, 0) ? "Yes" : "No") << endl;
		for(int i = 0; i < 102; i++) for(int j = 0; j < 101; j++)
			done[i][j][0] = done[i][j][1] = 0;
	}

	return 0;
}
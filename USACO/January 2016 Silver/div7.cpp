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
	// freopen("div7.in", "r", stdin);
	// freopen("div7.out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0; cin >> n;
	vector<int> ID(n + 1), prefix(n + 1), firstseen(7, -1);
	firstseen[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> ID[i];
		prefix[i] = (prefix[i - 1] + ID[i]) % 7;
	}
	for(int i = 1; i <= n; i++)
	{
		if(firstseen[prefix[i]] > -1) ans = max(ans, i - firstseen[prefix[i]]);
		else firstseen[prefix[i]] = i;
	}
	cout << ans;

	return 0;
}
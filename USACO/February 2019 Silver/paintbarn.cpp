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
	int n, k, ans = 0; cin >> n >> k;
	vector<vector<int>> antiprefix(1002, vector<int> (1002));
	vector<vector<int>> coats(1002, vector<int> (1002));
	while(n--)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		antiprefix[x1][y1]++;
		antiprefix[x2][y1]--;
		antiprefix[x1][y2]--;
		antiprefix[x2][y2]++;
	}
	for(int i = 0; i < 1002; i++) for(int j = 0; j < 1002; j++)
	{
		coats[i][j] = antiprefix[i][j];
		if(i - 1 > -1) coats[i][j] += coats[i - 1][j];
		if(j - 1 > -1) coats[i][j] += coats[i][j - 1];
		if(i - 1 > -1 && j - 1 > -1) coats[i][j] -= coats[i - 1][j - 1];
		ans += coats[i][j] == k;
	}
	cout << ans;

	return 0;
}
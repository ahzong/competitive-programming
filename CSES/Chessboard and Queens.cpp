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

ll ans = 0;
vector<string> board(8);
vector<bool> c(8);
vector<bool> d1(15);
vector<bool> d2(15);

void brute(int r)
{
	if(r == 8)
	{
		ans++;
		return;
	}
	for(int i = 0; i < 8; i++)
		if(board[r][i] == '.' && !c[i] && !d1[r - i + 7] && !d2[r + i])
		{
			c[i] = d1[r - i + 7] = d2[r + i] = 1;
			brute(r + 1);
			c[i] = d1[r - i + 7] = d2[r + i] = 0;
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 8; i++) cin >> board[i];
	for(int i = 0; i < 8; i++) c[i] = 0;
	for(int i = 0; i < 15; i++) d1[i] = d2[i] = 0;
	brute(0);
	cout << ans;

	return 0;
}
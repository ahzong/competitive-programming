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

int ans = 0;
string s;
bool visited[7][7];

bool ok(int x, int y)
{
	return x >= 0 && y >= 0 && x < 7 && y < 7 && !visited[x][y];
}

void brute(int x, int y, int c)
{
	if(!x && y == 6)
	{
		ans += (c == 48);
		return;
	}
	visited[x][y] = 1;
	if((s[c] == '?' || s[c] == 'L') && (!(!ok(x - 1, y) || (!ok(x - 2, y) && ok(x - 1, y - 1) && ok(x - 1, y + 1))))) brute(x - 1, y, c + 1);
	if((s[c] == '?' || s[c] == 'R') && (!(!ok(x + 1, y) || (!ok(x + 2, y) && ok(x + 1, y - 1) && ok(x + 1, y + 1))))) brute(x + 1, y, c + 1);
	if((s[c] == '?' || s[c] == 'U') && (!(!ok(x, y - 1) || (!ok(x, y - 2) && ok(x - 1, y - 1) && ok(x + 1, y - 1))))) brute(x, y - 1, c + 1);
	if((s[c] == '?' || s[c] == 'D') && (!(!ok(x, y + 1) || (!ok(x, y + 2) && ok(x - 1, y + 1) && ok(x + 1, y + 1))))) brute(x, y + 1, c + 1);
	visited[x][y] = 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	brute(0, 0, 0);
	cout << ans;

	return 0;
}
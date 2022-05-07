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
	int m, s; cin >> m >> s;
	if(s == 0)
	{
		cout << (m == 1 ? "0 0" : "-1 -1");
		return 0;
	}
	if(9 * m < s)
	{
		cout << "-1 -1";
		return 0;
	}
	// minimum
	if((s - 1)/9 == m - 1)
	{
		cout << (s - 1) % 9 + 1 << string(m - 1, '9') << ' ';
		cout << string(m - 1, '9') << (s - 1) % 9 + 1;
		return 0;
	}
	cout << 1;
	for(int i = 0; i < m - 2 - (s - 1)/9; i++) cout << 0;
	cout << (s - 1) % 9;
	for(int i = 0; i < (s - 1)/9; i++) cout << 9;
	cout << ' ';
	// maximum
	s = 9 * m - s;
	for(int i = 0; i < m - s/9 - 1; i++) cout << 9;
	cout << 9 - s % 9;
	for(int i = 0; i < s/9; i++) cout << 0;

	return 0;
}
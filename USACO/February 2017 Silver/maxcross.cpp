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
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, b, ans = INF32; cin >> n >> k >> b;
	vector<int> psum(n + 1);
	vector<bool> signal(n + 1, 1);
	for(int i = 0; i < b; i++)
	{
		int ID; cin >> ID;
		signal[ID] = 0;
	}
	for(int i = 1; i <= n; i++) psum[i] = psum[i - 1] + !signal[i];
	for(int i = k; i <= n; i++) ans = min(ans, psum[i] - psum[i - k]);
	cout << ans;

	return 0;
}
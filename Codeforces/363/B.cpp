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
	int n, k; cin >> n >> k;
	vector<int> h(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	int cur = 0;
	for(int i = 0; i < k; i++) cur += h[i];
	int mini = cur;
	int ans = 1;
	for(int i = k; i < n; i++)
	{
		cur += h[i];
		cur -= h[i - k];
		if(cur < mini)
		{
			mini = cur;
			ans = i - k + 2;
		}
	}
	cout << ans;

	return 0;
}
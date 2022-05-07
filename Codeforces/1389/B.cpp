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
		int n, k, z, ans = 0; cin >> n >> k >> z;
		vector<int> a(n);
		vector<int> pre(k + 1);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(i <= k) pre[i] = !i ? a[i] : a[i] + pre[i - 1];
		}
		for(int i = 0; i <= z; i++) for(int j = 0; j <= k - 2 * i; j++)
			ans = max(ans, pre[k - 2 * i] + i * (a[j] + a[j + 1]));
		cout << ans << endl;
	}

	return 0;
}
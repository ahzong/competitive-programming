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
	int n, q, m; cin >> n >> q >> m;
	vector<int> a(n);
	vector<vector<int>> que(q, vector<int> (3));
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < q; i++) cin >> que[i][0] >> que[i][1] >> que[i][2];
	while(m--)
	{
		int b; cin >> b;
		for(int i = q - 1; i > -1; i--) if(que[i][1] <= b && b <= que[i][2])
		{
			if(que[i][0] == 1) b = (b > que[i][1] ? b - 1 : que[i][2]);
			else b = que[i][2] - b + que[i][1];
		}
		cout << a[b - 1] << ' ';
	}

	return 0;
}
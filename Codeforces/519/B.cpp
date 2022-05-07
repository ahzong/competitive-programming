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
	int n; cin >> n;
	vector<int> a(n), b(n - 1), c(n - 2);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n - 1; i++) cin >> b[i];
	for(int i = 0; i < n - 2; i++) cin >> c[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for(int i = 0; i < n; i++)
	{
		if(i == n)
		{
			cout << a[n - 1] << endl;
			break;
		}
		if(a[i] != b[i])
		{
			cout << a[i] << endl;
			break;
		}
	}
	for(int i = 0; i < n - 1; i++)
	{
		if(i == n - 1)
		{
			cout << b[n - 2];
			break;
		}
		if(b[i] != c[i])
		{
			cout << b[i];
			break;
		}
	}

	return 0;
}
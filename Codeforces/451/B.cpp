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
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> b = a;
	sort(b.begin(), b.end());
	int i = 0, j = n - 1;
	while(i < n && a[i] == b[i]) i++;
	if(i == n)
	{
		cout << "yes" << endl << "1 1";
		return 0;
	}
	while(a[j] == b[j]) j--;
	int l = i, r = j;
	while(i <= r && a[i] == b[j])
	{
		i++;
		j--;
	}
	if(i == r + 1) cout << "yes" << endl << l + 1 << ' ' << r + 1;
	else cout << "no";

	return 0;
}
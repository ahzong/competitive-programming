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
	ll n, I; cin >> n >> I;
	ll power = (8 * I)/n;
	ll k = (power <= 60 ? (1LL<<power) : INF64);
	vector<int> b;
	map<int, int> freq;
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a;
		freq[a]++;
	}
	if(k >= freq.size())
	{
		cout << 0;
		return 0;
	}
	ll s = 0;
	for(auto x : freq) b.push_back(x.second);
	for(int i = 0; i < k; i++) s += b[i];
	ll ans = n - s;
	for(int i = k; i < b.size(); i++)
	{
		s += b[i];
		s -= b[i - k];
		ans = min(ans, n - s);
	}
	cout << ans;

	return 0;
}
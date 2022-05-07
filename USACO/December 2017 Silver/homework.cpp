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
	ll bestnum = 0, bestdenom = 1;
	vector<int> ans;
	vector<ll> score(n + 1), suffixsum(n + 1), suffixmin(n + 1);
	for(int i = 1; i <= n; i++) cin >> score[i];
	suffixsum[n] = suffixmin[n] = score[n];
	for(int i = n - 1; i; i--)
	{
		suffixsum[i] = suffixsum[i + 1] + score[i];
		suffixmin[i] = min(suffixmin[i + 1], score[i]);
	}
	for(int k = 1; k <= n - 2; k++)
	{
		ll num = suffixsum[k + 1] - suffixmin[k + 1], denom = n - k - 1;
		if(bestnum * denom < bestdenom * num)
		{
			bestnum = num;
			bestdenom = denom;
		}
	}
	for(int k = 1; k <= n - 2; k++)
	{
		ll num = suffixsum[k + 1] - suffixmin[k + 1], denom = n - k - 1;
		if(bestnum * denom == bestdenom * num) ans.push_back(k);
	}
	for(auto x : ans) cout << x << ' ';

	return 0;
}
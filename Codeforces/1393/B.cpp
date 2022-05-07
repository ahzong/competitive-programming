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
	int n, q, c2 = 0, c4 = 0, c6 = 0, c8 = 0; cin >> n;
	map<int, int> freq;
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a;
		freq[a]++;
	}
	for(auto x : freq)
	{
		if(x.second >= 8) c8++;
		if(x.second >= 6) c6++;
		if(x.second >= 4) c4++;
		if(x.second >= 2) c2++;
	}
	cin >> q;
	while(q--)
	{
		char c; cin >> c;
		int x; cin >> x;
		if(c == '+') 
		{
			freq[x]++;
			if(freq[x] == 8) c8++;
			if(freq[x] == 6) c6++;
			if(freq[x] == 4) c4++;
			if(freq[x] == 2) c2++;
		}
		else
		{
			if(freq[x] == 8) c8--;
			if(freq[x] == 6) c6--;
			if(freq[x] == 4) c4--;
			if(freq[x] == 2) c2--;
			freq[x]--;
		}
		if(c8)
		{
			cout << "YES" << endl;
			continue;
		}
		if(c6 && c2 >= 2)
		{
			cout << "YES" << endl;
			continue;
		}
		if(c4 && (c2 >= 3 || c4 >= 2))
		{
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}

	return 0;
}
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
	string s; cin >> s;
	int x = 7 - (s[0] - '0');
	for(int mask = 0; mask < 8; mask++)
	{
		int i = mask, cur = -((s[1] - '0') + (s[2] - '0') + (s[3] - '0')), j = 1;
		string ops = string(3, '-');
		while(i)
		{
			if(i & 1)
			{
				cur += 2 * (s[j] - '0');
				ops[j - 1] = '+';
			}
			i /= 2;
			j++;
		}
		if(cur == x)
		{
			cout << s[0] << ops[0] << s[1] << ops[1] << s[2] << ops[2] << s[3] << "=7";
			return 0;
		}
	}

	return 0;
}
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
		int n, k = 0; cin >> n;
		vector<string> grid(n);
		for(int i = 0; i < n; i++)
		{
			cin >> grid[i];
			for(int j = 0; j < n; j++) k += grid[i][j] == 'X';
		}
		for(int i = 0; i < 3; i++)
		{
			int cnt = 0;
			for(int r = 0; r < n; r++) for(int c = (i + r) % 3; c < n; c += 3)
				cnt += grid[r][c] == 'X';
			if(cnt <= k/3)
			{
				for(int r = 0; r < n; r++)
				{
					for(int c = 0; c < n; c++)	
					{
						if(c % 3 == (i + r) % 3)
							cout << (grid[r][c] == 'X' ? 'O' : grid[r][c]);
						else cout << grid[r][c];
					}
					cout << endl;
				}
				break;
			}
		}
	}

	return 0;
}
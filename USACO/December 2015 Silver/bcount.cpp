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
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	// #ifndef ONLINE_JUDGE
	// freopen(".in.txt", "r", stdin);
	// freopen(".out.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q; cin >> n >> q;
	vector<int> breedID(n + 1), prefix1(n + 1), prefix2(n + 1), prefix3(n + 1);
	for(int i = 1; i <= n; i++)
	{
		cin >> breedID[i];
		prefix1[i] = prefix1[i - 1] + (breedID[i] == 1);
		prefix2[i] = prefix2[i - 1] + (breedID[i] == 2);
		prefix3[i] = prefix3[i - 1] + (breedID[i] == 3);
	}
	while(q--)
	{
		int a, b; cin >> a >> b;
		cout << prefix1[b] - prefix1[a - 1] << ' ';
		cout << prefix2[b] - prefix2[a - 1] << ' ';
		cout << prefix3[b] - prefix3[a - 1] << endl;
	}

	return 0;
}
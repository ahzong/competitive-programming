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

set<int> s;
vector<int> spf(1e6 + 1);

void sieve()
{
    spf[1] = 1;
    for(int i = 2; i < 1e6 + 1; i++) spf[i] = i;
    for(int i = 4; i < 1e6 + 1; i += 2) spf[i] = 2; 
    for(int i = 3; i * i < 1e6 + 1; i++)
    {
        if(spf[i] == i) for(int j = i * i; j < 1e6 + 1; j += i) if(spf[j] == j)
        	spf[j] = i; 
    }
}

bool factorise(int x)
{
    while(x != 1)
    {
        int temp = spf[x];
       	if(!s.count(temp)) s.insert(temp);
       	else return 0;
        while(x != 1 && !(x % temp)) x /= temp;
    }
    return 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	int n; cin >> n;
	bool ok = 1;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		ok = factorise(a[i]);
		if(!ok) break;
	}
	if(ok)
	{
		cout << "pairwise coprime";
		return 0;
	}
	int g = a[0];
	for(int i = 1; i < n; i++) g = __gcd(g, a[i]);
	cout << (g == 1 ? "setwise coprime" : "not coprime");

	return 0;
}
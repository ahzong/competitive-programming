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

struct Node
{
	int l, r;
	bool b[2][2];
	public:
		Node()
		{
			b[0][0] = b[0][1] = b[1][0] = b[1][1] = 0;
		}
};

vector<Node> seg;
vector<vector<int>> a;

Node merge(int tl, int tr, Node lc, Node rc)
{
	int tm = (tl + tr)/2;
	Node ret;
	ret.l = tl;
	ret.r = tr;
	for(int l = 0; l < 2; l++) for(int r = 0; r < 2; r++)
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++)
			ret.b[l][r] |= lc.b[l][i] && rc.b[j][r] && a[tm][i] <= a[tm + 1][j];
	return ret;
}

void build(int v, int tl, int tr)
{
	if(tl == tr)
	{
		seg[v].l = seg[v].r = tl;
		seg[v].b[0][0] = seg[v].b[1][1] = 1;
		return;
	}
	int tm = (tl + tr)/2;
	build(2 * v, tl, tm);
	build(2 * v + 1, tm + 1, tr);
	seg[v] = merge(tl, tr, seg[2 * v], seg[2 * v + 1]);
}

void update(int v, int tl, int tr, int pos, vector<int> x)
{
	if(tl == tr)
	{
		a[pos] = x;
		return;
	}
	int tm = (tl + tr)/2;
	if(pos <= tm) update(2 * v, tl, tm, pos, x);
	else update(2 * v + 1, tm + 1, tr, pos, x);
	seg[v] = merge(tl, tr, seg[2 * v], seg[2 * v + 1]);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n;
	a.resize(n);
	seg.resize(4 * n);
	for(int i = 0; i < n; i++)
	{
		a[i].resize(2);
		cin >> a[i][0] >> a[i][1];		
	}
	build(1, 0, n - 1);
	cin >> m;
	while(m--)
	{
		int x, y; cin >> x >> y;
		bool ans = 0;
		x--; y--;
		vector<int> tmp = a[x];
		update(1, 0, n - 1, x, a[y]);
		update(1, 0, n - 1, y, tmp);
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) ans |= seg[1].b[i][j];
		cout << (ans ? "TAK" : "NIE") << endl;
	}

	return 0;
}
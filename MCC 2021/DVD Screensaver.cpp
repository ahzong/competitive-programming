#include <bits/stdc++.h>
#include "data.h"

using namespace std;
typedef long long ll;

int main()
{
	for(int q = 0; q < Q; q++)
	{
		ll h = H[q], w = W[q], t = T[q];
		ll r = ((t/(h - 1)) & 1) ? h - (t % (h - 1)) : t % (h - 1) + 1;
		ll c = ((t/(w - 1)) & 1) ? w - (t % (w - 1)) : t % (w - 1) + 1;
		cout << r << ' ' << c << endl;
	}

	return 0;
}
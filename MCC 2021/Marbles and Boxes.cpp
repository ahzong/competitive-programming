#include <bits/stdc++.h>
#include "data.h"

using namespace std;
typedef long long ll;

int main()
{
	ll net = 0, ans = 0;
	for(int i = 0; i < N; i++)
	{
		net += A[i] - B[i];
		ans += abs(net);
	}
	cout << ans;

	return 0;
}
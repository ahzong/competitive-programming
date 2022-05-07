#include <bits/stdc++.h>
#include "data.h"

using namespace std;

int main()
{
	for(int i = 0; i < T; i++)
	{
		int oc = 0, ec = 0;
		for(int j = 0; j < N[i]; j++)
		{
			oc += (C[i][j] & 1);
			ec += !(C[i][j] & 1);
		}
		cout << (oc >= 3 || (ec >= 2 && oc >= 1) ? "YES" : "NO") << endl;
	}

	return 0;
}
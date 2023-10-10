//https://pastebin.com/vCCfrQQZ
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1e4;

int main()
{
	string s,t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	int x[MAXN];
	for (int i = 0; i < MAXN; i++)
		x[i] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			x[i + j + 1] += (s[i] - '0') * (t[j] - '0');

	int l = n + m - 1;
	for (int i = l; i > 0; --i)
	{
		if(x[i] > 9)
		{
			x[i-1] += x[i] / 10;
			x[i] %= 10;
		}
	}

	int j;
	for (j = 0; j <= l; j++)
		if(x[j] > 0) break;

	for (int i = j; i <= l; i++)
		cout << x[i];
	
	return 0;
}
/* OpenIT KFU
https://pastebin.com/zSeSr1wb

A  = 4 5 8 19 1 2 2 3
ways 2 2 2  2 2 2 2 2 

Always 2 variants : use or not use ith element of array A
Summary 2^n variants 

Bin      Ten
00000000 0
00000001 1
00000010 2
00000011 3
...
10010001 145 
...
11111111 2 ^ n - 1

Binary operaations
------------------

n 	   =  101010111000    
k      =  101000001110
n & k  =  101000001000
n | k  =  101010111110
n ^ k  =  000010110110
n << 1 = 1010101110000
n >> 1 =   10101011100

if (n & 1) is equal if (n % 2 == 1)
n >> m is equal n / pow(2, m)
n << m is equal n * pow(2, m)
*/

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
	long long n, ans, k;
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");
	cin >> n;
	vector <long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	long long _2n = 1;// = pow(2, n);
	// for (int i = 0; i < n; i++)
	// 	_2n *= 2;


	_2n = 1 << n; long long sum = 0;
	for (long long mask = 0; mask < _2n; mask++)
	{	
		long long msk = mask;
		// for (int i = 1; i <= n; i++)
		// 	if ((msk >> i) & 1)
			   //((msk & (1 << i))

		long long i = 0;
		while (msk > 0)
		{
			//if (msk % 2 == 1)
			if (msk & 1)
			{
				sum += a[i];
				//v.push_back(a[i]);
			}
			i++;
			msk >>= 1;
			//msk /= 2;	
		}

		if (sum == k) ans = mask;
		sum = 0;
	}

	for (long long i = 0; i < n; i++)
		if ((ans >> i) & 1)
			cout << a[i] << " ";

	//cout << ans << endl;
	return 0;
}
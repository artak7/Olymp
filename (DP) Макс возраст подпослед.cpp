//https://pastebin.com/1th1YZ48
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1001, M = 1e4+1;

int main()
{
	int a[N], b[N], m;
	cin >> m;
	b[0] = -M;
	for (int i = 1; i <= m; ++i){
		cin >> a[i];
		b[i] = M;
		/*for (int j = 1; j <= j; ++j)         // O(N)
			if (a[i] > b[j-1] && a[i] < b[j])
			{
				b[j] = a[i];
				break;
			}
		*/
		int j = upper_bound(b, b + i + 1, a[i]) - b; // O(log2(N))
		b[j] = a[i];		
	}
	
	int i;
	for (i = 0; b[i + 1] < M; i++);
	
	cout << i;
	return 0;
}
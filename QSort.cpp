#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N] = {8, 7, 6, 0, 9, 6, 5, 3, 1, 2};

void qsort(int *a, int l, int r)
{
    if (l >= r) return;
    int x = rand() % (r-l+1) + l;
    int i = l;
    int j = r;
    //while (i < j)
    do
    {
        while (a[i] < a[x])
        {
            i++;
        }
        while (a[j] > a[x])
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++; j--;
        }

    } while (i < j);
    qsort(a, i, r);
    qsort(a, l, j);
}

int main()
{
    int n;
    cin >> n;
    for
    qsort(a, 0, N - 1);
    for (auto i : a)
        cout << i << " ";

}
//https://pastebin.com/FF3X8Xiy
//Author Artak
//надо потестить
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

typedef long long ll;
typedef long double ld;


const int MAXN = 1000;
int a[MAXN];

void qsort(int l, int r)
{
	if (l >= r) 
		return; //условие выхода из рекурсии

	int newl = l, newr = r, reference_elem = a[l + rand() % (r - l + 1)]; // (l + r) / 2 использовать плохо: найдется тест, на котором сортировка будет работать за O(n^2)
 
	while (newl <= newr)
	{
		while (a[newl] < reference_elem) //если нужно отсортировать по убыванию - ставите здесь знак >
			newl++;

		while (reference_elem < a[newr]) //если нужно отсортировать по убыванию - ставите здесь знак >
			newr--;
 
		if (newl <= newr)
		{
			swap(a[newl], a[newr]);
			newl++; newr--;
		}
	}
 
	qsort(l, newr);
	qsort(newl, r);
}

void merge(int sort_array[], int l, int mid, int r)
{
    int tmp[MAXN], t, i = l, j = mid + 1, k = l;    
	//necessary size of tmp = r - l + 2
    while (i <= mid && j <= r) 
	{
        if (sort_array[i] < sort_array[j]) //если нужно отсортировать по убыванию - ставите здесь знак >
		{
            tmp[k] = sort_array[i];
            i++;
		}
        else
		{
            tmp[k] = sort_array[j];
            j++;
		}
		k++;
	}
 
	for (t = i; t <= mid; t++)
	{
        tmp[k] = sort_array[t];
		k++;
	}
 
	for (t = j; t <= r; t++)
	{
        tmp[k] = sort_array[t];
		k++;
	}
 
	for (t = 0; t < k; t++)
		sort_array[t] = tmp[t];
}
 

void merge_sort(int sort_array[], int l, int r) 
{
    if (l >= r) return; //условие выхода из рекурсии
    int mid = (l + r) / 2;
    merge_sort(sort_array, l, mid);
    merge_sort(sort_array, mid + 1, r);
    merge(sort_array, l, mid, r);
}

int main() 
{
    ifstream cin("input.txt"); 
    ofstream cout("output.txt");
	
	int n;
	cin >> n;

	//check
	if (n > MAXN)
	{
		cout << "error! need to change const MAXN" << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
		cin >> a[i];

	//qsort(0, n - 1); //границы я взял включительно, здесь на ваше усмотрение
	merge_sort(a, 0, n - 1); //границы я взял включительно, здесь на ваше усмотрение

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

    return 0;
}
//Author Artak
#include <bits/stdc++.h>
using namespace std;
#define FILES freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define FastIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll long long
#define vll vector <ll>

void VBinarySearch2()
{
    ll n, x, l = 0, count;
    cin >> n >> x;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (ll count = n-1; count; count /= 2)
    {   //lowerbound                //upperbound
        if (a[l + count/2] < x)     //(!(a[l+count/2] <= x))
        {
            l += count/2 + 1;
            count--;
        }
    }
    cout << l << endl;
}

void VBinarySearch()
{
    ll n, x, l = 0, r, m;
    cin >> n >> x;
    vll a(n); r = n - 1;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (l < r)
    {   
        m = (l + r) / 2;
        /* lowerbound too but not necessarily
        if (a[m] == x) {l = m; break;}*/
        //lowerbound   //upperbound
        if (a[m] < x)  //(!(a[m] <= x))
            l = m + 1;
        else
            r = m;//r = m+1; if the equality condition used (look upper)
    }
    cout << l << endl;
}

/* Explane
    l = 0; r = n - 1; count = r - l + 1; 
    while (count)
    {
        //ll step = count / 2;
        //ll it = l + step;
        ll it = l + count / 2;
        //cerr << count << " " << step << " " << l << endl;
        if (a[it] < x)//a[it]
        {
            //l += count/2 + 1; 
            l = it + 1;
            //count -= step + 1;
            //count = (count - 1) / 2;
            count--;
            //count = count / 2 + count % 2 - 1;
        }
        // else
        //     count = count / 2;
        count /= 2;
    }
*/

ll BinarySearch2(vll &a, ll x)
{
    ll n = a.size(), l = 0;
    for (ll count = n-1; count; count /= 2)
    {   //lowerbound                //upperbound
        if (a[l + count/2] < x)     //(!(a[l+count/2] <= x))
        {
            l += count/2 + 1;
            count--;
        }
    }
    return l;
}

ll BinarySearch(vll &a, ll x)
{
    ll l = 0, r = a.size() - 1, m;
    while (l < r)
    {   
        m = (l + r) / 2;
        /* lowerbound too but not necessarily
        if (a[m] == x) {l = m; break;}*/
        //lowerbound   //upperbound
        if (a[m] < x)  //(!(a[m] <= x))
            l = m+1;
        else
            r = m;//r = m+1; if the equality condition used (look upper)
    }
    return l;
}

int main()
{
    FILES
    FastIO
    ll n, x, l = 0, r, count;
    cin >> n >> x;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << BinarySearch(a, x) << endl;
    cout << BinarySearch2(a, x) << endl;
    return 0;
}

//4 таске хадиева тк массив отсортированный, то все сдвинутые элементы меньше любого не сдвинутого элемента 
/*if (a[l] < a[m]) 
    l = m; 
else
    r = m;*/



// Author Artak
// вариант 1
#include <iostream>
#include <string>
#include <string.h> 
using namespace std;

int main()
{
    int l = 1, r = 1000001, mid; // правая граница не включительно
    string ans;
    while (r - l > 1) 
    {
        mid = (l + r) / 2;
        cout << mid << endl; //flush встроен в endl
        //вместо endl можно явно написать cout.flush();
        cin >> ans; 
        if (ans == "<")
            r = mid;
        else
            l = mid;
    }
        
    cout << "! " << l;
    return 0;
}


// Author Artak
// вариант 2
#include <iostream>
#include <string>
#include <string.h> 
using namespace std;

int main()
{
    int l = 1, r = 1000000, mid; // правая граница включительно
    string ans;
    while (r - l > 1) 
    {
        mid = (l + r) / 2;
        cout << mid << endl; //flush встроен в endl
        //вместо endl можно явно написать cout.flush();
        cin >> ans; 
        if (ans == "<")
            r = mid;
        else
            l = mid;
    }
    
    //осталось 2 варианта: ответ лежит либо в l, либо в r
    cout << r << endl;
    cin >> ans;
    if (ans == "<")
        cout << "! " << l;
    else
        cout << "! " << r;
        
    return 0;
}



n = int(input())
x = int(input())
a = list(map(int, input().split()))
l = 0
count = n - 1
while count > 0:
    if a[l + count // 2] < x:    # (!(a[l+count//2] <= x))
        l += count // 2 + 1
        count -= 1
   
    count //= 2

print(l)
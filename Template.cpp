/*#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <limits>
#include <numeric>
#include <functional>*/
//std::ifstream cin("input.txt");
//std::ofstream cout("output.txt");
#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5+1, M = 101, INF = 1e9+1;
#define FILES freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define FastIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define X first
#define Y second
#define l first
#define r second
#define popcount __builtin_popcountll
#define FORS(i, s, n) for (int i = (s); i < (n); ++i)
#define RFORS(i, s, n) for (int i = (n)-1; i >= (s); --i)
#define FOR(i, n) FORS(i, 0, n)
#define RFOR(i, n) RFORS(i, 0, n)
#define FI(n) FOR(i, n)
#define RFI(n) RFOR(i, n)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back((x))
#define SZ(c) int((c).size())
#define FOR_SETTED_BIT(bit, mask) for (int bit = 0; (mask) >> bit; ++bit) if (1&(mask >> bit))
#define FOR_NONZERO_SUBMASK(submask, mask) for (int submask=(mask); submask; submask=(submask-1)&(mask))
#define PI (3.141592653589793L)
#define MODULO ((ll)1e9+7LL)
#define MOD MODULO
 

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < ll, ll > pll;
typedef pair < ld, ld > pld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef list<int> li;
typedef list<ll> lll;
typedef list<ld> lld;
typedef list<pi> lpi;
typedef list<pll> lpll;
typedef list<pld> lpld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vld> vvld;
typedef vector<vpi> vvpi;
typedef vector<vpll> vvpll;
typedef vector<vpld> vvpld;
typedef vector<li> vli;
typedef vector<lll> vlll;
typedef vector<lld> vlld;
typedef vector<lpi> vlpi;
typedef vector<lpll> vlpll;
typedef vector<lpld> vlpld;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pi> spi;
typedef set<pll> spll;
typedef vector< list < pair < int, ll > > > AdjacencyLists;
typedef vvll AdjacencyMatrix;
typedef vvll matrix; 
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<class T> inline T sqr(const T &x) { return x * x; }
inline ll sqr(int x){return sqr<ll>(x);}
template<class T>T binpow(const T &a, ll n) { return n == 0 ? 1 : sqr(binpow(a, n / 2))* (n % 2 ? a : 1); }
ll binpow(ll a, ll n, ll modulo) { return n == 0 ? 1 : sqr(binpow(a, n / 2, modulo)) % modulo * (n % 2 ? a : 1) % modulo; }

//const int MOD = 998244353;
int add(int x, int y) {
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
int sub(int x, int y) {
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
int mult(int x, int y) {
    return ((ll)x * y) % MOD;
}
int bin_pow(int x, int p) {
    if (p == 0) return 1;
    if (p & 1) return mult(x, bin_pow(x, p - 1));
    return bin_pow(mult(x, x), p / 2);
}
int rev(int x) {
    return bin_pow(x, MOD - 2);
}
 
ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

inline ll phi (ll n) {
    ll result = n;
    for (ll i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

inline vll inverseAll(ll m)
{
    vll r(m);
    r[1] = 1;
    for (int i=2; i<m; ++i)
        r[i] = (m - (m/i) * r[m%i] % m) % m;
    return r;
}
//inline ll gcd(ll a, ll b) { return gcd(a, b, a, b); }
//inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll llrand()
{
    const ll lsbToFill = (sizeof(ll) << 3) - 1;
    const ll bitsFilledInIteration = popcount(RAND_MAX);
    ll number = 0;
    
    for (ll lsbFilled = 0; lsbFilled <= lsbToFill; lsbFilled += bitsFilledInIteration)
    {
        number ^= (((ll)rand()) << lsbFilled);
    }
    
    return number & numeric_limits<ll>::max();
}
inline ll llrand(ll begin, ll end)
{
    return begin + llrand() % (end - begin);
}
 
struct Dinic {
    struct Edge {
        int u, v;
        ll cap, flow;
        Edge() {}
        Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
    };
    
    int N;
    vector<Edge> E;
    vector<vector<int>> g;
    vector<int> d, pt;
    
    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
    
    void AddEdge(int u, int v, ll cap) {
        if (u != v) {
            E.emplace_back(Edge(u, v, cap));
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(Edge(v, u, 0));
            g[v].emplace_back(E.size() - 1);
        }
    }
    
    bool BFS(int S, int T) {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if (u == T) break;
            for (int k: g[u]) {
                Edge &e = E[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                    d[e.v] = d[e.u] + 1;
                    q.emplace(e.v);
                }
            }
        }
        return d[T] != N + 1;
    }
    
    ll DFS(int u, int T, ll flow = -1) {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < g[u].size(); ++i) {
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i]^1];
            if (d[e.v] == d[e.u] + 1) {
                ll amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (ll pushed = DFS(e.v, T, amt)) {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    
    ll MaxFlow(int S, int T) {
        ll total = 0;
        while (BFS(S, T)) {
            fill(pt.begin(), pt.end(), 0);
            while (ll flow = DFS(S, T))
                total += flow;
        }
        return total;
    }
};
 
vll Dijkstra(const AdjacencyLists &g, int s)
{
    vll d(SZ(g), numeric_limits<ll>::max() / 2LL);
    priority_queue < pair<ll, int> > q;
 
    d[s] = 0;
    q.emplace(-0, s);
    
    while (!q.empty())
    {
        while (q.top().first > d[q.top().second]) { q.pop(); }
        int v = q.top().second;
        
        q.pop();
        
        for (const auto &cw : g[v])
        {
            if (d[v] + cw.second < d[cw.first])
            {
                d[cw.first] = d[v] + cw.second;
                q.emplace(-d[cw.first], cw.first);
            }
        }
    }
    
    return d;
}
 
struct BinarySearchIterator : public std::iterator<std::forward_iterator_tag, bool>
{
    ll value;
    
    typename iterator_traits<BinarySearchIterator>::difference_type operator - (const BinarySearchIterator &it) const { return value - it.value; }
    
    BinarySearchIterator& operator ++() { ++value; return *this; }
    
    bool operator != (const BinarySearchIterator &it) const { return value != it.value; }
    
    bool operator*() const { /*insert code here*/ return true; }
};
 
template < int ALPHA >
class AhoCorasick
{
public:
    static const int ILLEGAL_INDEX;
    static const int ROOT;
    
    struct Node
    {
        bool leaf;
        int parent;
        int parentCharacter;
        int link;
        
        int next[ALPHA];
        int go[ALPHA];
        int outputFunction;
        
        Node(int parent = ILLEGAL_INDEX, int parentCharacter = ALPHA) :
            leaf(false),
            parent(parent),
            parentCharacter(parentCharacter),
            link(ILLEGAL_INDEX),
            outputFunction(ILLEGAL_INDEX)
        {
            fill_n(next, ALPHA, ILLEGAL_INDEX);
            fill_n(go, ALPHA, ILLEGAL_INDEX);
        }
    };
    
    vector<Node> tree = vector<Node>(1);
    
    AhoCorasick(){}
    AhoCorasick(int maxStatesNumber)
    {
        tree.reserve(maxStatesNumber);
    }
    
    template < class Iterator >
    void add(int length, const Iterator begin)
    {
        int vertex = ROOT;
        
        for (int i = 0; i < length; ++i)
        {
            if (ILLEGAL_INDEX == tree[vertex].next[begin[i]])
            {
                tree[vertex].next[begin[i]] = SZ(tree);
                tree.push_back(Node(vertex, begin[i]));
            }
            
            vertex = tree[vertex].next[begin[i]];
        }
        
        tree[vertex].leaf = true;
    }
    
    int getLink(int vertex)
    {
        assert(0 <= vertex && vertex < tree.size());
        
        if (ILLEGAL_INDEX == tree[vertex].link)
        {
            if (ROOT == vertex || ROOT == tree[vertex].parent)
            {
                tree[vertex].link = ROOT;
            }
            else
            {
                tree[vertex].link = go(getLink(tree[vertex].parent), tree[vertex].parentCharacter);
            }
        }
        
        return tree[vertex].link;
    }
    
    int go(int vertex, int character)
    {
        assert(0 <= character && character < ALPHA);
        assert(0 <= vertex && vertex < tree.size());
        
        if (ILLEGAL_INDEX == tree[vertex].go[character])
        {
            if (ILLEGAL_INDEX == tree[vertex].next[character])
            {
                tree[vertex].go[character] = ROOT == vertex ? ROOT : go(getLink(vertex), character);
            }
            else
            {
                tree[vertex].go[character] = tree[vertex].next[character];
            }
        }
        
        return tree[vertex].go[character];
    }
    
    int getOutputFunction(int vertex)
    {
        assert(0 <= vertex && vertex < tree.size());
        
        if (ILLEGAL_INDEX == tree[vertex].outputFunction)
        {
            if (tree[vertex].leaf || ROOT == vertex)
            {
                tree[vertex].outputFunction = vertex;
            }
            else
            {
                tree[vertex].outputFunction = getOutputFunction(getLink(vertex));
            }
        }
        
        return tree[vertex].outputFunction;
    }
};
 
template < int ALPHA > const int AhoCorasick<ALPHA>::ILLEGAL_INDEX = -1;
template < int ALPHA > const int AhoCorasick<ALPHA>::ROOT = 0;
 
struct UnionFind {
    vi parent;
    vi rank;
    UnionFind(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find_set (int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set (parent[v]);
    }
    void union_sets (int a, int b) {
        a = find_set (a);
        b = find_set (b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap (a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }
};
 
template < class T >
T assign(const T &a, const T &b) {
    return b;
}
 
template < class T >
struct SegmentTree {
    int n;
    vector<T> t;
    function<T(const T&, const T&)> operation;
    T default_value;
    function<T(const T&, const T&)> modification;
    
    SegmentTree() {}
    
    SegmentTree(const int n,
                const function<T(T, T)> &operation,
                const T &default_value=T(),
                const function<T(T, T)> &modification=assign<T>
    ) : SegmentTree(vector<T>(n, default_value), operation, default_value, modification)
    {}
    
    SegmentTree(const vector<T> &a,
                const function<T(T, T)> &operation,
                const T &default_value=T(),
                const function<T(T, T)> &modification=assign<T>
    ) :
            n((int)a.size()),
            t(n << 1),
            operation(operation),
            default_value(default_value),
            modification(modification)
    {
        copy(a.begin(), a.end(), t.begin() + n);
        
        for (int i = n - 1; i > 0; --i) t[i] = operation(t[i<<1], t[i<<1|1]);
    }
    
    void modify(int p, T value) {  // set value at position p
        p += n;
        
        for (t[p] = modification(t[p], value); p > 1; p >>= 1) t[p>>1] = operation(t[p], t[p^1]);
    }
    
    T query(int l, int r) const {  // sum on interval [l, r)
        T res = default_value;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = operation(res, t[l++]);
            if (r&1) res = operation(res, t[--r]);
        }
        return res;
    }
};

/* MY TEMPLATE */
/* Author ARTAK */

//template< typename T > 
struct point 
{ 
    ll x, y; 
    point(){}
    point(ll _x, ll _y) { x = _x; y = _y; }
    const point operator - (point _b) { return point(x-_b.x, y-_b.y); }
    point operator + (const point &a) const {return point(x + a.x, y + a.y);}
    int operator * (const point &a) const {return x * a.y - y * a.x;}
    const friend bool operator < (const point _c, const point _d)
    {   return _c.x < _d.x || _c.x == _d.x && _c.y < _d.y;  }
};
//const point dp[4] = {point(-1, 0), point(0, 1), point(1, 0), point(0, -1)};

//template< typename T > 
struct triple 
{
    ll x, y, z;
    triple(){}
    triple(ll _x, ll _y, ll _z) { x = _x; y = _y; z = _z; } 
    const triple operator+(triple _c) { return triple(x+_c.x, y+_c.y, z+_c.z); }
    const friend bool operator<(const triple _c, const triple _d)
    {   return _c.x < _d.x || _c.x == _d.x && _c.y < _d.y || _c.x == _d.x && _c.y == _d.y && _c.z < _d.z;  }
}; 
//const triple dt[6] = {triple(0, 0, 1), triple(0, 1, 0), triple(0, 0, -1), triple(0, -1, 0), triple(1, 0, 0)};

//const ld pi = 3.14159265359; //3,141592653589793238

//template< typename T > 
struct line
{
    ld a, b, c;
    line(){}
    line(point p1, point p2)
    {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -a * p2.x - b * p2.y;
    }

    void norm()
    {
        ld d = sqrt(a*a + b*b);
        a /= d; b /= d; c /= d;
    }

    ld dist(point p)
    {
        norm();
        return abs(a*p.x+b*p.y+c);
    }

    point projection(point p)
    {
        ld d = dist(p);
        return point(p.x + a * d, p.y + b * d);
    }
};

const matrix operator*(matrix a, matrix b) 
{
    //check
    ll na = a.size(), nb = b.size(), 
    ma = a[0].size(), mb = b[0].size();
    matrix c(na, (vector <ll> (mb)));
    for (int i = 0; i < nb; i++)
        if (na != b[i].size())
            return c;

    for (int i = 0; i < na; i++)
        if (nb != a[i].size())
            return c;
    
    for (int i = 0; i < ma; i++)
        for (int j = 0; j < nb; j++)
            for (int k = 0; k < na; k++)
                c[i][j] += a[i][k] * b[k][j];

    return c; 
}

ll mul(ll a, ll b) 
{
    ll q = ld(a) * b / MOD;
    ll result = a * b - q * MOD;
    while (result < 0)
        result += MOD;
    while (result >= MOD)
        result -= MOD;

    return result;
}

//template <typename T>
ll pow(ll a, ll n) 
{/* rec
    if (n == 0) return 1;
    if (n % 2 == 0) 
    {
        ll tmp = pow(a, n / 2); 
        return mul(tmp, tmp);
    } else 
        return mul(a, pow(a, n - 1));
*/

//non rec
    ll res = 1;
    while (n) 
    {
        if (n & 1) res *= a;
        a *= a; n >>= 1; // n /= 2;
    }

    return res;
}

//fibonacci
matrix pow(matrix a, ll n)
{
    matrix res(2, vector <ll> (2));
    res[0][0] = res[0][1] = res[1][0] = 1;
    while (n)
    {
        if (n & 1) res = res * a;
        a = a * a; n >>= 1;
    }

    return res;
}

ll gcd(ll a, ll b) 
{
    while (a > 0 && b > 0) 
    {
        if (b > a) swap(a, b);
        a %= b;
    }
    
    return a + b;
}

ll lcm(ll a, ll b) 
{ 
    ll g = gcd(a, b);
    if (!g) g++;
    return a / g * b;
}

vector <int> Pi(string s)
{
    //s = t + "#" + s;
    int n = s.size();//, result = 0; 
    vector <int> p(n, 0);

    for (size_t i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];

        if (s[i] == s[j])
            p[i] = j + 1;

        //if (j == m)
        //  result++;
    }

    return p;
}

vector <int> Z(string s)
{
    int n = s.length(), l = 0, r = 0;
    vector <int> z(n, 0);

    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r-i+1, z[i-1]);
        
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])       
            z[i]++;
        
        if (i + z[i] - l > r)
        {
            l = i;
            r = i + z[i] - l;
        }
    }
    return z;
}

inline bool intersect_1 (ld a, ld b, ld c) {
    if (a > b)  swap (a, b);
    return a <= c && c <= b;
}
 
bool intersect (point a, point b, point c)
{
    return intersect_1 (a.x, b.x, c.x) && intersect_1 (a.y, b.y, c.y);
}

ll dotproduct(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

ll crossproduct(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}

ld areatriangle(point a, point b, point c) 
{
    //return crossproduct((b - a), (c - a)) / 2.0;
    return ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) / 2.0;
}

int decomposition(int n)
{
    ll ans = 0;
    int degree = 0;
    int i = 2;
    while (i * i <= n)
        if (n % i == 0)
            degree++;
        else
        {
            //decmp.push_back(degree);
            ans += degree;
            i++;
        }

    return ans;
}

void eratosphene(bool *a, int n)
{
    a[0] = a[1] = false;
    for (int i = 2; i <= n; ++i)
       a[i] = true;
    
    for (int i = 2; i <= n; ++i)
        if (a[i])
            for (int j = i*i; j <= n; j+=i)
                a[j] = false;
}

ll C(ll n, ll m)
{
    if (m > n) return 0;
    if (n > 0 && n > m) 
        return C(n - 1, m - 1) + C(n - 1, m) % MOD;
    else
        return 1;
}

vector <bool> u;
vvll g;
ll n, m, s[N];

ll dfs(int v)
{
    u[v] = 1; 
    ll m = s[v];
    for (auto to : g[v])
        if (!u[to])
            m = min(m, dfs(to));

    return m;
}

vvll depth, matr;
void bfs(int it) 
{
    queue <int> q;
    q.push(it);
    u[it] = 1;
    while (!q.empty())
    {
        int i = q.front(); q.pop();
        for (int j = 0; j < n; j++)
            if (!u[j] && matr[i][j])
            {
                q.push(j);
                u[j] = 1;
                depth[it][j] = depth[it][i] + 1;
            }
    }
}

void dijkstra(int n, int start)
{
    //global
    vvpi g;
    /*int m, a, b, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> w;
        //if (a != b)
        g[--a].push_back({--b, w});
        //g[b].push_back({a, w});
    }*/

    vector <ll> d(n, INF), u(n, 0);//,p(n);
    d[start] = 0;
    /* N*N + M
    for (int i = 0; i < n; ++i)
    {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || d[j] < d[v]))
                v = j;

        used[v] = true;
        if (d[v] == INF) break;
        for (int j = 0; j < g[v].size(); ++j)
        {
            int to = g[v][j].l, len = g[v][j].r;
            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                //p[to] = v;
            }
        }
    }*/

    //m log n
    set < pair<int,int> > q;
    q.insert (make_pair (d[start], start));
    while (!q.empty()) 
    {
        int v = q.begin()->r;
        q.erase(q.begin());

        for (int j = 0; j < g[v].size(); ++j)
        {
            int to = g[v][j].l, len = g[v][j].r;
            if (d[v] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                //p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

// int fin(int x) {
//     return (p[x] == -1 ? x : p[x] = fin(p[x]));
// }

/* END TEMPLATE */

/*
MY SEGMENTTREE
ll a[N], t[4*N];

void build(ll v, ll tl, ll tr)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = t[2*v] + t[2*v+1]; //your operation
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r) return 0;
    if (l == tl && r == tr)
        return t[v];
    
    ll tm = (tl + tr) / 2;
    return sum(2*v, tl, tm, l, min(tm, r)) + sum(2*v+1, tm+1, tr, max(tm+1, l), r);
}

ll t_lcm(int v, int tl, int tr, int l, int r)
{
    if (l > r) return 0;
    if (l == tl && r == tr)
        return t[v];

    int tm = (tl + tr) / 2;
    //return sum(2 * v, tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return lcm(t_lcm(2 * v, tl, tm, l, min(r, tm)), t_lcm(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

//rec
void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
        t[v] = new_val;
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2*v, tl, tm, pos, new_val);
        else
            update(2*v+1, tm+1, tr, pos, new_val);

        t[v] = t[2*v] + t[2*v+1];
    }
}

/ * non rec
void update(int v, int tl, int tr, int pos, ll new_val)
{
    while (tl != tr)
    {
        int tm = (tl + tr) / 2;
        v *= 2;
        if (pos <= tm)
            tr = tm;
        else
            v++, tl = tm + 1;

        t[v] = new_val - t[v];
    }

    t[v] = new_val;
}* /
*/

ll binsearch2(vll &a, ll x)
{
    /*ll n, x, l = 0, r;
    cin >> n >> x;
    vll a(n);
    FI(n) cin >> a[i];*/
    ll n = a.size(), l = 0;
    for (ll count = n-1; count; count /= 2)
    {   //lowerbound                //upperbound
        if (a[l + count/2] < x)     //(!(a[l+count/2] <= x))
        {
            l+= count/2 + 1;
            count--;
        }
    }
    return l;
}

ll binsearch(vll &a, ll x)
{
    /*
    ll n, x, l = 0, r;
    cin >> n >> x;
    vll a(n); r = n - 1;
    FI(n) cin >> a[i];
    */
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

void solve1()
{
    ll n, sum = 0, mx = 0, ans = 0;
    cin >> n;
    bool ok = true;
    vpll at(n);
    //map <ll, bool> u;
    FI(n) {cin >> at[i].X;}// u[at[i].X] = 1;}
    FI(n) {cin >> at[i].Y;}
    //map <ll, ll> nextfree;
    sort(ALL(at));
    //vector work;
    FI(n-1)
    {
        if (at[i].X == at[i+1].X)
        {
            sum = 0; mx = at[i].Y;
            ll newi = i;
            FORS(j, i, n)
            {
                if (at[j].X - at[j+1].X > 1)
                    break;
                mx = min(mx, at[j].Y);
                if (at[j].X != at[i].X)
                    sum += mx;
                else 
                {
                    newi = j;
                    sum = mx;
                }
            }
            i = newi;
            ans += sum;
        }
    }
    //if (ok) cout << "YES"; else cout << "NO";
    cout << ans << endl;
}

void solve()
{
    ll n;
    cin>>n;
    string s(n, '2');
    s[n-1] = '3';
    ll sum = 2 * n + 1;
    if (sum % 3 == 0) s[0] = '4';
    if (n < 2) cout << -1 << endl; else cout << s << endl;
}

int main()
{
    FILES
    FastIO
    ll test = 1; cin >> test;
    for (int it = 0; it < test; it++)
    {
        solve();
    }
    return 0;
}
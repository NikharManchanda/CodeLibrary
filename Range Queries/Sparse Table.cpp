// Time: Fri Oct 29 19:32:41 2021
// User: Nikhar Manchanda aka N.F
#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//less<int> , greater<int> ,less_equal<int>, greater_equal<int>
//			data_type,null_type, less<data_type>
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
// 1).find_by_order(idx)                        (returns iterator)
// 2).order_of_key(key)                         (returns number of keys less than a key)
// 3).upper_bound(key)													(returns iterator)
// 4).lower_bound(key)         									(returns iterator)
// 5).erase(key)	                              (erases key if present)
/*------------------------------------------------------------*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/*------------------------------------------------------------------*/
#define int               long long
#define rev               greater<int>()
/*------------------------------------------------------------------*/
#define nl                "\n"
#define pb                push_back
#define pf                push_front
#define all(x)            (x).begin(),(x).end()
#define rall(x)           (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define fr                first
#define sc                second
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define fix(prec)         {cout << setprecision(prec) << fixed;}
#define lcm(a, b)         ((a) * (b)) / __gcd(a, b)
#define imin              INT_MIN
#define imax              INT_MAX
#define lmin              LLONG_MIN
#define lmax							LLONG_MAX
#define Yes               cout<<"Yes\n"
#define No                cout<<"No\n"
#define YES               cout<<"YES\n"
#define NO                cout<<"NO\n"
#define yes               cout<<"yes\n"
#define no                cout<<"no\n"
#define show(A) for (auto i: A) cout << i << " "; cout << '\n';
#define endl "\n"
#define sz(x)             (int)((x).size())

const double Pi = acos(-1.0);
const int mod = 1e9 + 7;
const int mod2 = 998244353;

const int N1 = 4e5 + 5;
const int N2 = 2e6 + 5;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
/*----------------------------------------------------------*/
void setIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
void local()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/*--------------------------------------------------------*/

//N1 vs powers of 2 [0,1,2,..log2(N1)]
int sparse_table[N1 + 5][25];
int k = 25;
int lg[N1 + 5];
void build(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		sparse_table[i][0] = a[i];
	}
	for (int j = 1; j <= k; j++)
	{
		for (int i = 0; i + (1 << (j - 1)) < n; i++)
			sparse_table[i][j] = min(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
	}
}
void calc_log()
{
	lg[1] = 0;
	for (int i = 2; i <= N1; i++)
	{
		lg[i] = lg[i / 2] + 1;
	}
}
signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	calc_log();
	k = lg[n];
	build(a, n);
	for (int l = 1; l <= q; l++)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		int len = lg[y - x + 1];
		cout << min(sparse_table[x][len], sparse_table[y + 1 - (1 << (len))][len]) << nl;
	}

	return 0;

}

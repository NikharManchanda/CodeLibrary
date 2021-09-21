#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------------*/
#define int   long long
/*------------------------------------------------------------------*/
int binpow(int a, int b)
{
  //Calculates n^m
  if (b == 0)
    return 1;
  int res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
/*------------------------------------------------------------------*/
signed main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  cout << binpow(n, m);

  return 0;

}

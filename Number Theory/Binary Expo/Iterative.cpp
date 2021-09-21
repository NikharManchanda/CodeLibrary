#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------------*/
#define int   long long
/*------------------------------------------------------------------*/
int binpow(int a, int b)
{
  //Calculates a^b

  int res = 1;
  while (b > 0)
  {
    if (b & 1)    //  if b is odd
      res *= a;
    a = a * a;
    b >>= 1;      //  b=b/2;
  }
  return res;

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
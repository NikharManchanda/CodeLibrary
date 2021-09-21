#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------------*/
#define int   long long
/*------------------------------------------------------------------*/
int modpow(int a, int b, int M)
{
  //Calculates a^b % M
  a %= M;
  int res = 1;
  while (b)
  {
    if (b & 1)
      res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
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
  const int M = 1e9 + 7;
  cout << modpow(n, m, M);

  return 0;

}
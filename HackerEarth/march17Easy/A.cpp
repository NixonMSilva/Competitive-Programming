#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 2 * (ll)(1e5) + 10;

inline void main2() {
  int n, k; scanf("%d %d", &n, &k);
  int a = 0;
  for(int i = 0; i < n; ++i) {
    int f; scanf("%d", &f);
    a = max(a, k - f);
  }
  printf("%d\n", a); 
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}
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

void arquivo() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}

const int N = 100010;

int n;
int v[N];
ll s = 0;

int main() {
  //arquivo();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", v + i);
    s += v[i];
  }
  sort(v, v + n);
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    s -= v[i];
    ans += s;
  }
  printf("%lld\n", ans);
  return 0;
}
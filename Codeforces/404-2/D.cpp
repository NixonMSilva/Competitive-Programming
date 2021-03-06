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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 2 * (1e5 + 10);

const ll MOD = 1e9 + 7LL;

inline ll addMod(ll a, ll b, ll md = MOD) {
  a += b;
  if(a >= md) a -= md;
  return a;
}

inline ll mulMod(ll a, ll b, ll md = MOD) {
  return ((a % md) * (b % md)) % md;
}

inline ll powMod(ll a, ll p, ll md = MOD) {
  ll ans = 1;
  while(p) {
    if(p & 1) ans = mulMod(ans, a);
    a = mulMod(a, a);
    p >>= 1;
  }
  return ans;
}


ll fat[N], invFat[N];
ll LOpen[N], LClose[N];
ll ROpen[N], RClose[N];

inline ll C(int n, int r) {
  if(r > n) return 0;
  return mulMod(fat[n], mulMod(invFat[r], invFat[n - r]));
}

char s[N];
int n;

int main() {
  scanf(" %s", s);
  n = strlen(s);
  fat[0] = 1; invFat[0] = 1;
  for(int i = 1; i <= n; ++i) {
    fat[i] = mulMod(fat[i - 1], i);
    invFat[i] = powMod(fat[i], MOD - 2);
  }
  for(int i = 0; i < n; ++i) {
    LOpen[i] = (s[i] == '(');
    LClose[i] = (s[i] == ')');
    if(i) {
      LOpen[i] += LOpen[i - 1];
      LClose[i] += LClose[i - 1];
    }
  }

  for(int i = n - 1; i >= 0; --i) {
    ROpen[i] = (s[i] == '(');
    RClose[i] = (s[i] == ')');
    if(i != n - 1) {
      ROpen[i] += ROpen[i + 1];
      RClose[i] += RClose[i + 1];
    }
  }
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '(') ans = addMod(ans, C(LOpen[i] + RClose[i] - 1, LOpen[i]));
  }
  printf("%lld\n", ans);  
  return 0;
}
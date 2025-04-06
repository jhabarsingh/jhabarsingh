#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define loop(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
// #define int ll
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>    vi;
typedef vector<ll>    vll;
typedef vector<pii>    vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vll>    vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}

//======================= DEBUGGER ========================
string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

//======================= DEBUGGER ENDS ========================

int expo(int base, int exp);

//======================= FUNCTION DECLARATION END =============

const int mod = 1000000007;


//======================= GLOBAL VARIABLE END ==================


int CIN = true;
void solve() {
  int n, m, x, i, j;
  cin >> n;
  vi arr(n);

  loop(i, 0, n) cin >> arr[i];


  int sum = accumulate(arr.begin(), arr.end(), 0);
  sort(all(arr));

  float ans = INT_MIN;
  float a = 0;
  loop(i, 0, n - 1) {
    a += arr[i];
    float temp = (a / (float)(i + 1) + (sum - a) / (float)(n - i - 1));
    ans = max(ans, temp);
  }


  printf("%.9f\n", ans);
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif

  int t = 1;
  if (CIN)
    cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

int expo(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

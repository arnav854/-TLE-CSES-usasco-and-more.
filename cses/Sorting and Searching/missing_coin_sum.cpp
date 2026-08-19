#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long int ll;
#define F first 
#define S second   
#define vi vector<int>
#define dvi vector<vector < int >>
#define vill vector<ll>
#define dvill vector<vector <ll>>
#define MP make_pair 
#define PB push_back   
#define f_b(i,a,b) for (int i = a ; i <= b ;i++ )  
#define f(i,a,b) for (int i = a ; i <b ;i++ )  
#define all(v) sort(v.begin(),v.end())
#define rev_all(v) sort(v.begin(),v.end(), greater<int>())

const int MX = 15000000;
const ll MOD = 1000000007;
vector<ll> pf(MX + 1, 0);

#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \

void calc_primes() {
    for (int i = 1; i <= MX; i++) pf[i] = i;

    for (int i = 2; 1LL * i * i <= MX; i++) {
        if (pf[i] != i) continue;

        for (int j = 1LL * i * i; j <= MX; j += i) {
            if (pf[j] == j) pf[j] = i;
        }
    }
}

ll lcm(ll a, ll b) {
   ll g = __gcd(a, b);
   return (a % g == 0) ? (a / g) * b : (b / g) * a;
}
ll mpow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

vector<int> manacher(string s) {
    string t;
    for (auto c : s) {
        t += string("#") + c;
    }
    t += "#";

    int n = t.size();
    vector<int> p(n + 2);
    int l = 0, r = 1;

    for (int i = 1; i <= n; i++) {
        if (i <= r) {
            p[i] = min(r - i, p[l + (r - i)]);
        }

        while (t[i - p[i]] == t[i + p[i]]) {
            p[i]++;
        }

        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    return vector<int>(begin(p) + 1, end(p) - 1);
}
/* Carefull !!! 
1. Array bound , int overflow , special case , for n=1 ?  
2. Break things into subproblems or smaller problems rather than big problems
    since big problems cant be solved  
3.  try to breakk given into possibilities and track it one by one (subproblems) 
4.  IMP : Breaks question into 2 bit parts positive and negative and solve both ways  
    there is a case when both turn out to be give answer but probabilty makes 
    distiction 
5.  Understand the nature of each thing what their nature is telling us like 
    string vs int 
6.  try to change diagram of question as : a1 a2 a3 .. or a1 _ a3 _ a4 
    here _ are blank space I mean try to change the diagram too  
7.  distict vs non distinct think in array   
8.  if u get memory limit exceeded try to remove the above parts taking space
    i.e if O(N^2) space u take 
9.  Figure 'kyu' in every intution why stopped ( Hard to do )
*/
void solve() {
    int n  ; cin >> n ;
    vi v (n) ;
    take_v (v) ;
    all (v) ;
    int miss = -1 ;
    vill pre(n+1) ;
    // 1 2 2 7 9 
    for (int i = 1 ; i <=n ; i++ ){
        if (pre[i-1]+1 >=v[i-1]){
            pre[i]+=pre[i-1] +v[i-1] ; 
        }else {
            miss = pre[i-1]+1 ;
            break ;
        }
    }
    if ( miss ==-1 ){
        cout << pre[n]+1 << endl ;
    }else {
        cout << miss << endl ; 
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
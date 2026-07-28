#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define F first 
#define S second   
#define vi vector<int>
#define vill vector<ll>
#define dvill vector<vector <ll>>
#define MP make_pair 
#define PB push_back   
#define f_b(i,a,b) for (int i = a ; i <= b ;i++ )  
#define f(i,a,b) for (int i = a ; i <b ;i++ )  
#define all(v) sort(v.begin(),v.end())

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

/* Carefull !!! 
1. Array bound , int overflow , special case , for n=1 ?  
2. Break things into subproblems or smaller problems rather than big problems
    since big problems cant be solved  
3.  try to breakk given into possibilities and track it one by one (subproblems) 
4.  Breaks question into 2 bit parts positive and negative and solve both ways  
    there is a case when both turn out to be give answer but probabilty makes 
    distiction 
5.  Understand the nature of each thing what their nature is telling us like 
    string vs int 
6.  try to change diagram of question as : a1 a2 a3 .. or a1 _ a3 _ a4 
    here _ are blank space I mean try to change the diagram too  
7.  distict vs non distinct think in array   
*/
void solve() {
    int n , m ; cin >> n >> m; 
    vi v (n) ;
    take_v (v) ;
    for (int i= 1 ; i < n ; i++ ){
        if (v[i-1]-v[i]>m){
            v[i]=v[i-1]-m ; 
        }
    }
    for (int i= n-2 ; i >=0 ; i-- ){
        if (v[i+1]-v[i]>m){
            v[i]=v[i+1]-m ;
        }
    }
    
    out_v(v); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
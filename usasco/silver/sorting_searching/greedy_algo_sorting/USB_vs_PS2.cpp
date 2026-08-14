#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define F first 
#define S second   
#define MP make_pair 
#define PB push_back   
#define f_b(i,a,b) for (int i = a ; i <= b ;i++ )  
#define f(i,a,b) for (int i = a ; i <b ;i++ )  
#define all(v) sort(v.begin(),v.end())

const int MX = 15000000;
const ll MOD = 1000000007;
vector<ll> pf(MX + 1, 0);

void calc_primes() {
    for (int i = 1; i <= MX; i++) pf[i] = i;

    for (int i = 2; 1LL * i * i <= MX; i++) {
        if (pf[i] != i) continue;

        for (int j = 1LL * i * i; j <= MX; j += i) {
            if (pf[j] == j) pf[j] = i;
        }
    }
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

void solve() {
    int a , b , c ; cin >> a >> b >> c ;
    int m ; cin >> m ;
    vector < pair < int , string >> v (m) ;
    for (auto &it :v)  cin >> it.first >> it.second ; 
    all(v) ; ll ans = 0 ; ll ans2 = 0 ;
    for (auto &it : v)
    {
        if (it.second == "USB")
        {
            if (a>0){
                ans++ ; 
                ans2+=(it.first) ;a-- ;
            }else if (c>0){
                ans++ ; ans2+=(it.first) ;c-- ;
            }
        }
        else if (it.second == "PS/2")
        {
            if (b>0){
                ans++ ; 
                ans2+=(it.first) ;
                b-- ;
            }else if (c>0){
                ans++ ; ans2+=(it.first) ;
                c-- ;
            }
        }
        
    }

    cout << ans << " "<< ans2 ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
 
#define vi vector<int>
#define dvi vector<vector < int >>
#define vill vector<ll>
#define dvill vector<vector <ll>>


const int MX = 15000000;

vector<int> pf(MX + 1, 0);

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

void solve() {
    int n ; cin >> n ; 
    vi v (n) ;
    take_v(v) ;
    vi store (31);
    for ( int i = 0 ; i <n ; i++ ){
        for (int j = 0 ; j < 31 ; j++ ){
            if (((1 << j )& v[i])){
                store[j]++ ;
            }
        }
    } 
    int hcf  = 0 ;
    for ( int i = 0 ; i <= 30 ; i++ ){
        if (store[i]>0){
             hcf = store[i] ;
             break ;
        }
    }
    if ( hcf == 0 ) {
        for ( int i = 1 ; i <= n ; i++ ){
            cout << i << " ";
        }
        cout << endl ;


    }else {
        for ( int i = 0 ; i < 31 ; i++){
            if (store[i]!=0 )
            hcf = __gcd(hcf , store[i]) ;
        }
        vector < int > st ;
        for ( int i = 1 ; i *i <= hcf ; i++ ){
            if ( hcf % i == 0 ){
                st.push_back(i);
                if ((hcf / i)  != i ){
                    st.push_back(hcf/i) ;
                }
            }
        } 
        sort (st.begin(),st.end()) ;  
        out_v(st) ;
    }
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc_primes();
    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
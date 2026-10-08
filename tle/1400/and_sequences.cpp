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
#define all(v) sort(v.begin(),v.end())
#define rev_all(v) sort(v.begin(),v.end(), greater<int>())
# define v_min(v) *min_element(v.begin() , v.end()) 
#define v_max *max_element(v.begin() , v.end()) 
# define v_min_f_idx min_element(v.begin() , v.end()) -v.begin()
# define v_max_f_idx max_element(v.begin() , v.end()) -v.begin()

#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \
int MOD = 1e9 + 7 ;
void solve() {
    int n ; cin >> n ; 
    vi v (n) ;
    take_v(v) ;
    int x = v[0] ;
    for ( int i = 1 ; i < n  ; i++ ){
        x = (x & v[i]) ;
    }
    ll ans = 1;
    for ( int i = 1 ; i <=n-2 ; i++ ){
        ans = (((ans) * (i)))%MOD ; 
    }
    ll cnt = 0 ;
    for ( int i =0 ; i < n ; i++ ){
        if ( v[i] == x ){
            cnt ++ ;
        }
    }
    cnt %=MOD ;
    cout << ((( cnt * ( cnt-1))%MOD)* (ans ))%MOD << endl  ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
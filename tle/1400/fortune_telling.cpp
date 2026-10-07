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


#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \
string A =  "Alice" ;
string B = "Bob";
void solve() {
    int n , x  ; cin >> n >> x  ;
    ll y ; cin >> y ; 
    vi v(n) ;
    take_v(v) ;
    int ans = 0 ;
    for ( int i =0 ; i < n ;i++ ){
        if (v[i]%2)  ans ++ ;
    }
    int k1 = 0 ; 
    int k2 = 0 ;
    if ( x % 2 ) k1++ ;
    else k2 ++ ; 
    if ( y % 2 ){
        if ( (k1 + ans )%2) cout << A << endl ;
        else cout << B << endl ;
    }else {
        if ( ((k1 + ans )%2) == 0 ) cout << A << endl ;
        else cout << B << endl ;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
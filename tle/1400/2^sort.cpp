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

void solve() {
    int n , k ; cin >> n >> k ; 
    vector < bool > flg (n-1) ;
    vi v(n) ;
    take_v(v) ;
    for ( int i = 1 ; i < n ; i++ ) {
        if (2*v[i] > v[i-1]){
            flg[i-1] = true ; 
        }else flg[i-1] = false ; 
    } 
    /*
       x  y   z   x  x   x 
         Yes Yes No Yes Yes 
    
    */
    // for ( int i =0  ; i < n-1 ; i+=1 ){
    //     cout << flg[i] << " " ;
    // }
    // cout << endl ; 
    
    int ans = 0 ;
    int l = 0 ; int yes = 0 ;
    for ( int i = 0 ; i < n-1 ; i++ ){
        if (flg[i] == true )yes++ ;
        else yes-- ; 
        if (i-l+1 == k ){
            if (yes == k){
                ans ++ ; 
            }
            if (flg[l]) yes-- ;
            else yes++ ; 
            l++ ; 
        }
    }
    cout << ans << endl ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
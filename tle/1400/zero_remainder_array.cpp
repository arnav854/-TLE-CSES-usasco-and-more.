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

void solve() {
    int n , k ; cin >> n>> k; 
    map < int , int > mp ;
    ll ans = 0 ;
    for( int i =0 ;  i < n ;i++ ){
        int x ; cin >> x ; x%=k ;
        if ( x !=0 ){
            mp[k-x]++ ;
        }
        if( x != 0) ans =1 ;

    }
    // 2 1 2 0 
    // 0 1 2 
    if ( ans == 0 ) cout << ans << endl ;
    else {
        ans =  0;
        for (auto it: mp){
            ans = max(ans, 1LL * it.F + 1LL * (it.S - 1) * k);
        }
        ans ++ ;
        cout << ans << endl ;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
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
    int n , l , k ; cin >> n >> l >> k ;
    vi v (n) ;
    take_v(v) ;
    if (n <= k ) cout << n << endl ; 
    else {
        set < pair < int , int > , greater < pair < int , int >>> st ; 
        int p = v[0] ; 
        for (int  i = 1 ; i < n  ; i++ ){
            st.insert({v[i]-p , i}) ;
            p = v[i] ; 
        }
        vi temp(n) ;
        temp[0] = 1 ; k-- ;
        for (auto it : st){
            if (k==0) break ;
            temp[it.S] = 1 ;
            k-- ;
        }
        int ans = 1 ;
        for ( int i = 1 ; i < n ; i++ ){
            if ( temp[i] ==1){
                ans +=1 ;
            }else {
                ans +=(v[i]-v[i-1]) ;
            }
        }
        cout << ans << endl;  
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
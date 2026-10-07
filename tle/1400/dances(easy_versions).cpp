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
    int n ; cin >> n ; 
    vi a (n) , b (n) ;
    int m ; cin >> m ;
    a[0] = m ;
    for (int i = 1 ; i < n ; i++ ) cin >> a[i] ;
    for (int i = 0 ; i < n ; i++ ) cin >> b[i] ;
    all(a) ; all(b) ;
    int l(0) , r(0) ;
    int ans = 0 ;
    while ( r < n ){
        if (a[l] < b[r]) {
            ans ++ ;
            l++ ;
        }
        r++ ;

    }
    cout << n - ans << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
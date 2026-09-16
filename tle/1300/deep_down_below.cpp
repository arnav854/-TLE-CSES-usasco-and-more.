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



#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \
    
void solve() {
    int n ; cin >> n ; 
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        }
    };
        
    multiset<pair<int, int>, cmp> st;
    for ( int i = 0 ; i < n ; i++ ){
        int x ; cin >> x ;
        int ans = 0 ; 
        for (int j = 0 ; j < x  ; j ++ ){
            int a ; cin >> a ; 
            a-=j ;
            ans = max ( ans , a) ;
        }
        st.insert({ans , x} );
    }
    int l = 0 ;  int end =1e9+ 3  ; int mid = l + ( end -l )/2 ;
    int ans  = 1e9 + 3  ;
    while ( l <= end ){
        ll power = mid ;
        bool  flag = true ;
        for ( auto it : st ){
            
            if (it.first <  power ){
                power+= it.S ; 
            }else {
                flag = false ;
                break ; 
            }
        }
        if ( flag ){
            ans = min (ans , mid ) ;
            end = mid - 1 ;
        }else {
            l = mid + 1 ;
        }
        mid = l + ( end - l )/2 ;
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
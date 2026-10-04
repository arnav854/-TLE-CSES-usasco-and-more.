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

string ne = "No" ;
string y = "Yes" ;
void solve() {
    int n ; cin >> n ;
    vi v (n) ;
    take_v(v) ;
    int zero = 0  ; 
    int maxi =0  ;
    for (int i =  0 ;  i < n ; i++ ){
        if (v[i]%2 ){
            v[i]+=(v[i]%2) ;
            if (v[i]%2 == 0 ) zero++ ;
        }
        maxi = max ( maxi , v[i]) ;
    }
    all(v) ;
    if (zero < n && zero >=1  ){
        cout << ne << endl ;
    }else if (zero == n  ){
        for (int i = 0 ;i < n-1 ; i++){
            if (v[i]!=v[i+1]){
                cout << ne << endl ; 
                return ; 
            }

        }
        cout << y << endl ; 
    }else {
        vector < vector < int >> st (5 , vector < int >(4))  ;
        // 2   4  8 6  
        // 20  2  6 14 
        for ( int i = 1 ;  i < 4 ; i++ ){
            st[i][i] = 20;
            int cnt =0  ;
        }
        for (int  i = 0 ; i < n-1 ; i++ ){
            int x = maxi- v[i];
            vector < int > temp = st[(x/2)] ;
            all(temp) ;
            for (int j = 3; j >= 0 ; j--){
                x%=temp[j] ; 
            }
            if ( x != 0 ){
                cout << ne << endl ; 
                return ;
            }
        }
        cout << y << endl ; 

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
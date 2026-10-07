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
    int  r, c ; cin >> r >> c ; 
    vector < vector < int >> mat ( r , vector < int > (c)) ;
    for ( int i =0  ; i < r ; i++ ){
        for ( int j =0  ; j < c ; j++ ) {
            cin >> mat[i][j] ;
        }
    }
    map < int , vector < pair < int , int >>> mp ;
    for ( int i =1  ; i <= r ; i++){
        for ( int j =1 ;j <= c ; j++ ){
            int col = mat[i-1][j-1];
                mp[col].push_back( {i ,j }) ;
        }
    }
    ll  ans = 0 ;
    for (auto it : mp){
        if (it.S.size()>1){
            vector < int >temp1 , temp2 ;
            for ( auto it2 : it.S) {
                temp1.push_back(it2.F) ; 
                temp2.push_back(it2.S) ; 
            }
            all(temp1) ;all(temp2) ;
            /*
                1 2 6 8 
            */
            ll sum = 0 ;
            for ( int i = 1 ; i < temp1.size() ;i++ ){
                sum = sum + ((temp1[i]-temp1[i-1])*(i)) ;
                ans += sum ;
            }
            sum = 0 ; 
            for ( int i = 1 ; i < temp1.size() ;i++ ){
                sum = sum+ ((temp2[i]-temp2[i-1])*(i)) ;
                ans += sum ;
            }

        }
    }
    cout << ans << endl ; 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
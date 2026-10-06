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
    vector < int > flag (n , false  ) ;
    for ( int  i = 0 ; i <n  ;i++ ){
        int a , b ; cin >> a >> b ; 
        if ( a== -1){
            flag[i] = true ;
            continue;
        } 
        if ( b == 0 ){
            flag[a-1] =true ;
            flag[i] = true ;
            // 3 -> true  1 -> false 2 -> false 4 -> false 5->true 
        }

    }
    bool is = false  ;
    for ( int i = 0 ; i < n  ; i++){
        if (!flag[i]){
            is = true ;
            cout << i+1 << " " ;
        }

    }
    if ( !is ) cout << -1 << endl ;
    cout << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
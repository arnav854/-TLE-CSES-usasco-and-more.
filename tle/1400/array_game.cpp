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


#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \

/* Carefull !!! 
1. Array bound , int overflow , special case , for n=1 ?  
2. Break things into subproblems or smaller problems rather than big problems
    since big problems cant be solved  
3.  try to breakk given into possibilities and track it one by one (subproblems) 
4.  IMP : Breaks question into 2 bit parts positive and negative and solve both ways  
    there is a case when both turn out to be give answer but probabilty makes 
    distiction 
5.  Understand the nature of each thing what their nature is telling us like 
    string vs int 
6.  try to change diagram of question as : a1 a2 a3 .. or a1 _ a3 _ a4 
    here _ are blank space I mean try to change the diagram too  
7.  distict vs non distinct think in array   
8.  if u get memory limit exceeded try to remove the above parts taking space
    i.e if O(N^2) space u take 
9.  Figure 'kyu' in every intution why stopped ( Hard to do )
*/
void solve() {
    int n , k ;  cin >> n >> k ;
    vill v (n) ;
    take_v (v) ;
    set < ll > st;
    all(v) ;
    set < ll > temp1 ;

    // 42 47 50 54 62 79 
    // 5 3 4 

    ll x = v[0];

    for (int i = 0 ; i < n ; i++ ){
        for (int j = i+1 ; j < n ; j++ ){
            x = min(x, abs(v[i]-v[j]));
        }
    }

    if (k >= 3) {
        cout << 0 << endl;
    }
    else if (k == 1) {
        cout << x << endl;
    }
    else {

        for (int i = 0 ; i < n ; i++ ){
            for (int j = i+1 ; j < n ; j++ ){

                ll d = abs(v[i] - v[j]);  

                auto it = lower_bound(v.begin(), v.end(), d);

                if (it != v.end()) {
                    x = min(x, abs(d - *it));   
                }

                if (it != v.begin()) {          
                    --it;
                    x = min(x, abs(d - *it));
                }
            }
        }

        cout << x << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
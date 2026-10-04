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

const int MX = 15000000;
const ll MOD = 1000000007;
vector<ll> pf(MX + 1, 0);

#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \

void calc_primes() {
    for (int i = 1; i <= MX; i++) pf[i] = i;

    for (int i = 2; 1LL * i * i <= MX; i++) {
        if (pf[i] != i) continue;

        for (int j = 1LL * i * i; j <= MX; j += i) {
            if (pf[j] == j) pf[j] = i;
        }
    }
}


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
void calc(ll &nums , ll n  ){
    while (nums <=n ){
        if (nums * 10 <= n ){
            nums *=10 ;
        }else {
            nums *= ((n/nums)) ;
            break ;  
        }

    }
}
void solve() {
    int n , k ; cin >> n >> k ;
    int temp = n ; 
    ll two(0) , five(0) ; 
    ll nums = 1 ;
    while (temp > 1 ){
        if (temp%2 ==0 ){
            temp /= 2 ;
            two++ ;
        }else if ( temp % 5  == 0 ){
            temp /= 5 ;
            five ++ ;
            
        }else {
            break; 
        }
    }
    if (two == five){
        calc(nums , k ) ;
    }else if ( two < five){
        while ( nums*2 <= k && five-two >=1  ){
            two++ ;
            nums*= 2 ;
        }
        calc(nums , k ) ;


    }else {
        while ( nums*5 <= k &&  two -five >=1  ){
            five++ ;
            nums*= 5 ;
        }
        calc(nums , k ) ;
        
    }
    if ( nums == 1 ){
        cout << n * k << endl ; 
    }else {
        cout << nums * n << endl ;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc_primes() ;

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
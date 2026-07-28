#include <bits/stdc++.h>
using namespace std;
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
*/
void solve() {
    string s ; cin >> s ;
    int n = s.size() ;
    dvi temp (n , vector < int > (n)) ;
    dvi v (n+1 , vector < int > (n+1)); 
    for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {

        if (i == j)
            temp[i][j] = 1;

        else if (j == i + 1)
            temp[i][j] = (s[i] == s[j]);

        else
            temp[i][j] = (s[i] == s[j] && temp[i + 1][j - 1]);
    }
    }
    for (int i =1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++ ){
            if (temp[i-1][j-1]==1) v[i][j]++ ;
            v[i][j]+=(v[i-1][j]+v[i][j-1]-v[i-1][j-1]);
        }
    }
    int q ; cin >> q ;
    while ( q-- ){
        int a , b ; cin >>a  >> b  ;
        cout << v[b][b]-v[a-1][b]-v[b][a-1]+v[a-1][a-1] << endl ;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
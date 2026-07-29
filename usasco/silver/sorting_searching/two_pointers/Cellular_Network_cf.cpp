// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// #define F first 
// #define S second   
// #define vi vector<int>
// #define dvi vector<vector < int >>
// #define vill vector<ll>
// #define dvill vector<vector <ll>>
// #define MP make_pair 
// #define PB push_back   
// #define f_b(i,a,b) for (int i = a ; i <= b ;i++ )  
// #define f(i,a,b) for (int i = a ; i <b ;i++ )  
// #define all(v) sort(v.begin(),v.end())


// #define out_v(v) \
//  for (auto &x : v) \
//     cout << x << " "; \
//  cout << '\n';

// #define take_v(v) \
//  for (auto &x : v) \
//     cin>> x ; \

// void solve() {
//     int n, m;
//     cin >> n >> m;

//     ll dist = 2e9;

//     vi v1(n), v2(m);   // Fixed size
//     take_v(v1);
//     take_v(v2);

//     ll st = 0, last = dist;
//     ll ans = 0;

//     while (st <= last) {
//         ll mid = st + (last - st) / 2;   

//         int l = 0, r = 0;               

//         while (l < n && r < m) {
//             if (abs(v1[l] - v2[r]) <= mid)
//                 l++;
//             else
//                 r++;
//         }

//         if (l == n) {
//             ans = mid;
//             last = mid - 1;              // Fixed binary search update
//         } else {
//             st = mid + 1;                // Fixed binary search update
//         }
//     }

//     cout << ans << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     solve();
//     return 0;
// }

/// @@@ 2ND Approach 

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


void solve() {
    int n, m;
    cin >> n >> m;

    vill v1(n), v2(m);
    take_v(v1);
    take_v(v2);

    ll ans = 0;
    int r = 0;

    for (int l = 0; l < n; l++) {
        while (r + 1 < m &&
               abs(v1[l] - v2[r + 1]) <= abs(v1[l] - v2[r])) {
            r++;
        }
        ans = max(ans, abs(v1[l] - v2[r]));
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
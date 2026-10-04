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
    int n;
    cin >> n;

    vi v(n);
    vector<vector<int>> pre(n + 1, vector<int>(31));

    take_v(v);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 31; j++) {

            pre[i + 1][j] = pre[i][j];   // CHANGE

            if ((v[i] & (1 << j)) != 0) {
                pre[i + 1][j]++;         // CHANGE
            }
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {

        int a, b;
        cin >> a >> b;

        a--;

        int ans = -1;

        int l = a;
        int r = n - 1;
        int mid = r - (r - l) / 2;

        bool flag = true;

        while (l <= r) {

            flag = true;   // CHANGE

            for (int j = 30; j >= 0; j--) {

                if ((b & (1 << j)) != 0) {

                    if (pre[mid + 1][j] - pre[a][j] < mid - a + 1) {
                        flag = false;
                        break;
                    }

                } else {

                    if (pre[mid + 1][j] - pre[a][j] >= mid - a + 1) {
                        break;
                    }
                }
            }

            if (flag) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }

            mid = r - (r - l) / 2;
        }
        if ( ans ==- 1 ){
            cout << ans << " " ;
        }else cout << ans+1 << " ";

        
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}
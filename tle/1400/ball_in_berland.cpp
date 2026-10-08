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
# define v_min(v) *min_element(v.begin() , v.end())
#define v_max *max_element(v.begin() , v.end())
# define v_min_f_idx min_element(v.begin() , v.end()) -v.begin()
# define v_max_f_idx max_element(v.begin() , v.end()) -v.begin()



#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    map<int, vector<int>> mp, mp2;
    vi v1(k), v2(k);

    take_v(v1);
    take_v(v2);

    for (int i = 0; i < k; i++) {
        mp[v1[i]].push_back(v2[i]);
        mp2[v2[i]].push_back(v1[i]);
    }

    ll ans = 0;

    for (auto it : mp) {
        ll x = it.S.size();
        ans += x * (x - 1) / 2;
    }

    for (auto it : mp2) {
        ll x = it.S.size();
        ans += x * (x - 1) / 2;
    }

    cout <<(1LL*( (1LL*k) * (k - 1)) / 2) - ans << endl;
}

int main () {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
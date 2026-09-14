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
#define dvi vector<vector<int>>
#define vill vector<ll>
#define dvill vector<vector<ll>>
#define MP make_pair 
#define PB push_back   
#define f_b(i,a,b) for (int i = a; i <= b; i++)  
#define f(i,a,b) for (int i = a; i < b; i++)  
#define all(v) sort(v.begin(), v.end())
#define rev_all(v) sort(v.begin(), v.end(), greater<int>())

#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin >> x;

pair<int, int> call(int n, int &ans, map<int, vector<int>> &mp, string &s, int curr) {
    
    int b = 0;
    int w = 0;

    // Visit ALL children
    for (auto child : mp[curr]) {
        pair<int, int> p = call(n, ans, mp, s, child);
        b += p.S;
        w += p.F;
    }

    if (s[curr - 1] == 'W') {
        w++;
    } else {
        b++;
    }

    if (b == w && b > 0) {
        ans++;
    }

    return {w, b};
}

void solve() {
    int n;
    cin >> n;

    vi v(n - 1);
    take_v(v);

    string s;
    cin >> s;

    map<int, vector<int>> mp;

    for (int i = 1; i <= n; i++) {
        mp[i] = {};
    }

    for (int i = 1; i < n; i++) {
        mp[v[i - 1]].push_back(i + 1);
    }

    int ans = 0;

    call(n, ans, mp, s, 1);

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
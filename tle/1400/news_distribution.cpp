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
#define all(v) sort(v.begin(), v.end())
#define rev_all(v) sort(v.begin(), v.end(), greater<int>())
#define v_min(v) *min_element(v.begin(), v.end())
#define v_max *max_element(v.begin(), v.end())
#define v_min_f_idx min_element(v.begin(), v.end()) - v.begin()
#define v_max_f_idx max_element(v.begin(), v.end()) - v.begin()

#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin >> x;

int parent(int a, vi &v) {
    if (v[a] == a) return a;
    return v[a] = parent(v[a], v);
}

void merge(int a, int b, vi &v, vi &rank) {
    int x1 = parent(a, v);
    int x2 = parent(b, v);

    if (x1 != x2) {
        if (rank[x1] >= rank[x2]) {
            rank[x1] += rank[x2];
            v[x2] = x1; 
        } else {
            rank[x2] += rank[x1];
            v[x1] = x2; 
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vi v(n);
    vi rank(n, 1);

    for (int i = 0; i < n; i++) {
        v[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        if (x == 0) continue;

        int a;
        cin >> a;
        a--;

        for (int j = 1; j < x; j++) {
            int b;
            cin >> b;
            b--;
            merge(a, b, v, rank);
        }
    }

    vi ans(n);

    for (int i = 0; i < n; i++) {
        ans[parent(i,v)]++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[parent(i,v)] << " ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

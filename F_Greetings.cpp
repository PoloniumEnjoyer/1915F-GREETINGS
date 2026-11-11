// USING FENWICK TREE   

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> fTree;

int leastSignificantBit(int x) {

    return x & -x;
}

void updateTree(int i, int j) {

    for(; i <= n; i+= leastSignificantBit(i)) {

        fTree[i] += j;
    }
}

int query(int i) {

    int sum = 0;

    for(; i > 0; i -= leastSignificantBit(i)) {

        sum += fTree[i];
    }

    return sum;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {

        cin >> n;

        vector<pair<ll, ll>> arr(n);
        vector<ll> startingPosn(n);

        for(int i = 0; i < n; i++) {

            ll a, b;

            cin >> a >> b;
            arr[i] = {b, a};
            startingPosn[i] = a;
        }

        sort(arr.begin(), arr.end());
        sort(startingPosn.begin(), startingPosn.end());

        fTree.assign(n + 1, 0);

        ll ans = 0;

        for(int i = 0; i < n; i++) {

            int rank = lower_bound(startingPosn.begin(), startingPosn.end(), arr[i].second) - startingPosn.begin() + 1;

            ans += query(n) - query(rank);
            updateTree(rank, 1);
        }

        cout << ans << '\n';
    }
}
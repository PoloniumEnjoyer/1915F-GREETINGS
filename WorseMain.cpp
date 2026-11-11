#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        long long n;
        cin >> n;

        vector<pair<long long, long long>> p(n);

        for (int i = 0; i < n; i++) {

            cin >> p[i].first >> p[i].second;   
        }

        // REVERSING THE ORDER OF THE INTEGER PAIRS SO THAT THE VECTOR IS SORTED ON THE BASIS OF THE ENDING POINTS
        for(int i = 0; i < n; i++) {

            long long temp = p[i].first;
            p[i].first = p[i].second;
            p[i].second = temp;
        }

        // SORTING IN ASCENDING ORDER
        sort(p.begin(), p.end());

        unordered_map<long long, vector<pair<long long, long long>>> mp;
        vector<pair<long long, long long>> tempArr;

        for(int i = 0; i < n; i++) {

            if(i == 0) {

                tempArr.push_back({p[i].first - p[i].second, p[i].first});
            }

            else if(i > 0 && i < n - 1) {

                mp[p[i].second] = tempArr;
                tempArr.push_back({p[i].first - p[i].second, p[i].first});
            }

            else {

                mp[p[i].second] = tempArr;
            }
        }

        long long greeting{};

        for(auto &it : mp) {

            long long startingPoint = it.first;
            vector<pair<long long, long long>> possibleGreetings = it.second;

            for(auto &q : possibleGreetings) {

                if(q.first <= q.second - startingPoint) {

                    greeting++;
                }
            }
        }

        cout << greeting << '\n';
    }

    return 0;
}
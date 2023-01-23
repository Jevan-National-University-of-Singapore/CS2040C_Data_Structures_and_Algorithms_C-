#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N; cin >> N;
    ll catQueue = 200000; ll catCount = 0;
    priority_queue<tuple<ll, ll, string>> clinic_queue;
    unordered_map<string, ll> name_infectionLevel;
    unordered_map<string, ll> name_catQueue;
    unordered_set<string> cat_removed;
    for (ll i = 0; i < N; ++i) {
        ll case_type; string catName; ll infectionLevel; ll increaseInfection;
        cin >> case_type;
        if (case_type == 0) {
            cin >> catName >> infectionLevel;
            clinic_queue.push(make_tuple(infectionLevel, catQueue, catName));
            name_infectionLevel[catName] = infectionLevel;
            name_catQueue[catName] = catQueue;
            --catQueue;
            ++catCount;
        }
        else if (case_type == 1) {
            cin >> catName >> increaseInfection;
            auto search_infectionLevel = name_infectionLevel.find(catName);
            ll updated_infectionLevel = search_infectionLevel->second + increaseInfection;
            if (updated_infectionLevel > 100)
                updated_infectionLevel = 100;
            name_infectionLevel[catName] = updated_infectionLevel;
            auto search_catQueue = name_catQueue.find(catName);
            clinic_queue.push(make_tuple(updated_infectionLevel, search_catQueue->second, catName));
        }
        else if (case_type == 2) {
            cin >> catName;
            cat_removed.insert(catName);
            --catCount;
        } else if (case_type == 3) { // need to edit to make sure the PQ elements are deleted properly
            if (catCount == 0)
                cout << "The clinic is empty" << "\n";
            else {
                string top_cat = get<2>(clinic_queue.top());
                while (cat_removed.find(top_cat) != cat_removed.end()) {
                    clinic_queue.pop();
                    top_cat = get<2>(clinic_queue.top());
                }
                cout << top_cat << "\n";
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// CAN JUST USE UNORDERED_SET AND PQ TO DO THIS QUESTION
class clinic {
private:
    ll patient_count;
    vector<pair<ll, string>> binary_heap;
    unordered_map<string, ll> name_map;
    
    bool compare(pair<ll, string> p1, pair<ll, string> p2){
        if (get<0>(p1) > get<0>(p2))
            return true;
        else if (get<0>(p1) == get<0>(p2))
            return (get<1>(p1) < get<1>(p2));
        else
            return false;
    }

    ll left(ll i) {
        return 2 * i;
    }

    ll right(ll i) {
        return 2 * i + 1;
    }

    ll parent (ll i) {
        return i/2;
    }

    void shiftup(ll idx) {
        if (idx <= 1) {
            //root
            return;
        }
        if (compare(binary_heap[idx], binary_heap[parent(idx)])) {
            combined_swap(idx, parent(idx));
            shiftup(parent(idx));
        }
    }

    void shiftdown(ll idx) {
        if (idx > patient_count) {
            return;
        }
        ll max_idx = idx;
        if (left(idx) <= patient_count && compare(binary_heap[left(idx)], binary_heap[max_idx])) {
            max_idx = left(idx);
        }
        if (right(idx) <= patient_count && compare(binary_heap[right(idx)], binary_heap[max_idx])) {
            max_idx = right(idx);
        }
        if (max_idx != idx) {
            combined_swap(idx, max_idx);
            shiftdown(max_idx);
        }
    }

public:
    clinic() {
        patient_count = 0;
        binary_heap.assign(1, make_pair(-1, "dummy"));
    };
    
    void combined_swap(ll idx1, ll idx2) {
        swap(binary_heap[idx1], binary_heap[idx2]);
        name_map[get<1>(binary_heap[idx1])] = idx1;
        name_map[get<1>(binary_heap[idx2])] = idx2;
    }

    void push_clinic_queue(ll priority_value, string patient_name) { 
        binary_heap.push_back(make_pair(priority_value, patient_name));
        ++patient_count;
        name_map[patient_name] = patient_count;
        // bubble upwards
        shiftup(patient_count);
    }

    void pop_clinic_queue() {
        if (patient_count == 0) {
            return;
        }
        combined_swap(patient_count, 1);
        name_map.erase(get<1>(binary_heap[patient_count]));
        --patient_count;
        //swap first element with last element
        binary_heap.pop_back();
        shiftdown(1);
    }

    void remove_clinic_queue(string patient_name) {
        if (name_map.count(patient_name) == 0)
            return;
        else {
            auto search = name_map.find(patient_name);
            ll del_idx = search->second;
            combined_swap(del_idx, patient_count);
            // swap to-be deleted element with the last element
            name_map.erase(get<1>(binary_heap[patient_count]));
            --patient_count;
            binary_heap.pop_back();
            shiftup(del_idx);
            shiftdown(del_idx);
        }
    }

    string top_clinic_queue() { 
        assert(binary_heap.size() > 1);
        return get<1>(binary_heap[1]);
    }

    bool empty() {
        return patient_count == 0;
    }

    ll size() {
        return patient_count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clinic clinic;
    ll N; ll K;
    cin >> N >> K;
    for (ll i = 0; i < N; ++i) {
        ll Q; ll T; string M; ll S; ll priority_value;
        cin >> Q;
        if (Q == 1){
            cin >> T >> M >> S;
            priority_value = S - (K*T);
            clinic.push_clinic_queue(priority_value, M);
        }
        if (Q == 2) {
            cin >> T;
            if (clinic.empty()) {
                cout << "doctor takes a break" << "\n";
            } else {
                cout << clinic.top_clinic_queue() << "\n";
                clinic.pop_clinic_queue();
            }
        } 
        if (Q == 3) {
            cin >> T >> M;
            clinic.remove_clinic_queue(M);
        }
    }
    return 0;
}

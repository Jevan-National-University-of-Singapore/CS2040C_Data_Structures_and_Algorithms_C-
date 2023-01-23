#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

struct Comparator{
    public:
        bool operator()(string a, string b){
            if (string(a) < string(b)){
                return false;
            }
            return true;
        }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long N, max = 0, maxI = 0;;
    cin >> N;
    vector<long long>blocks;

    for (long long i = 0; i < N; ++i){
        long long b;
        cin >> b;
        blocks.push_back(b);
        if (b > max){
            max = b;
        }
    }


    for (long long i = 0; i < N; ++i){
        long long count;
        long long current = i;
        queue<vector<long long>>steps;
        vector<long long>first_steps;
        unordered_set<long long> visited;
        first_steps.push_back(i);
        steps.push(first_steps);
        visited.insert(i);
        if (blocks[i] == max){
            cout << 0 << " ";
        } else {
            while (!blocks.empty()){
                bool found = false;
                vector<long long>current_path = steps.front();
                vector<long long>current_path2 = steps.front();
                for (long long j = current_path.back() + 1; j < N; ++j){
                    if (blocks[j] > blocks[current_path.back()]){
                        if (visited.find(j) == visited.end()){
                            current_path.push_back(j);
                            steps.push(current_path);
                            visited.insert(j);
                            if (blocks[j] == max){
                                count = current_path.size()-1;
                                found = true;
                            }
                        }
                        break;
                    }
                }
                if (found){break;}


                for (long long j = current_path2.back() - 1; j >= 0; --j){
                    if (blocks[j] > blocks[current_path2.back()]){
                        if (visited.find(j) == visited.end()){
                            current_path2.push_back(j);
                            steps.push(current_path2);
                            visited.insert(j);
                            if (blocks[j] == max){
                                count = current_path2.size()-1;
                                found = true;
                            }
                        }
                        break;
                    }
                }
                if (found){break;}
                steps.pop();
            }

        
            cout << count << " ";
        }
    }
    
    
    


}
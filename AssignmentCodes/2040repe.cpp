//get_at_least_subtask1_and_2_for_both_tasks
#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    unordered_map<string, string>variables;
    long long N;
    cin >> N;
    for (long long i = 0; i < N; ++i){
        string cmd, varName;
        cin >> cmd >>  varName;
        if (cmd == "DECLARE"){
            string varType;
            cin >> varType;
            if (variables.find(varName) != variables.end()){
                cout << "MULTIPLE DECLARATION";
                break;
            } else {
                variables.insert({varName, varType});
            }
        } else if (cmd == "TYPEOF"){
            if (variables.find(varName)==variables.end()){
                cout << "UNDECLARED\n";
            } else {
                cout << variables[varName] << "\n";
            }
        }
    }
}
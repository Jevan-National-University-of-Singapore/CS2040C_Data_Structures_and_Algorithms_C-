//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	
	int N; string L; vector<char>A;
	cin >> N;
	cin.ignore();
	getline(cin,L);

	int error = 0;
    for (int i = 0; i < N; i++){
    	if (L[i] == '(')
    		A.push_back('(');
    	else if (L[i] == '[')
    		A.push_back('[');
    	else if (L[i] == '{')
    		A.push_back('{');
    	else if (L[i] == ')'){
    		if (A.empty() == true){
    			cout << ") " << i;
    			error++;
    			break;
    		}
    		else if ((A.back() == '[') or (A.back() == '{')){
    			cout << ") " << i;
    			error++;
    			break;
    		}
    		else
    			A.pop_back();
    	}
    	else if (L[i] == ']'){
    		if (A.empty() == true){
    			cout << "] " << i;
    			error++;
    			break;
    		}
    		else if ((A.back() == '(') or (A.back() == '{')){
    			cout << "] " << i;
    			error++;
    			break;
    		}
    		else
    			A.pop_back();
    	}
    	else if (L[i] == '}'){
    		if (A.empty() == true){
    			cout << "} " << i;
    			error++;
    			break;
    		}
    		else if ((A.back() == '[') or (A.back() == '(')){
    			cout << "} " << i;
    			error++;
    			break;
    		}
    		else
    			A.pop_back();
    	}

    }
    if (error == 0)
    	cout << "ok so far";


	return 0;
}
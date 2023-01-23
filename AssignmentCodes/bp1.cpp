#include <iostream>
#include <stdio.h>
#include<list>
#include <algorithm>
//arnarLLLBBun unnar

using namespace std;
int main (){
  char input;
  list<char> password;
  long long counterL=0;
  long long counterR =0;
  while(cin >> input){
    if (input == 'L'){
      counterL++;
    } else if (input == 'R'){
        counterR++;
    } else if (input == 'B'){
        list<char>::const_iterator it = password.begin();
        advance(it, password.size() - 1 - counterL + counterR);
        password.erase(it);
    } else if (counterL - counterR == password.size()){
        password.push_front(input);
    } else if (counterL - counterR == 0){
        password.push_back(input);
    } else {
      password.insert(password.begin(), password.size() - 1 - counterL + counterR, input);
    }
    for (list<char>::const_iterator it = password.begin(); it != password.end(); ++it){
        cout << *it ;
    }
    cout <<"\n";
  }


  for (list<char>::const_iterator it = password.begin(); it != password.end(); ++it){
    cout << *it ;
  }
}
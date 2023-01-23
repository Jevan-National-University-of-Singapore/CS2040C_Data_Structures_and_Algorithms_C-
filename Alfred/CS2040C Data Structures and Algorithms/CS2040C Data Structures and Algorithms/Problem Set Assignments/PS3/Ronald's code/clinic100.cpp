#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
#include <string.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int N; long long int K; cin >> N >> K;
    int Q; long long int T; string M; long long int S;
    unordered_map <string, long long int> database; /*pair<T,S>*/
    priority_queue <pair <long long int, string>> pq; 
    list <string> samelevel;
    while (N--){
        cin >> Q;
        if (Q == 1){
            cin >> T >> M >> S;
            database[M] = S-K*T;
			if (samelevel.empty() == false){
				if (database[samelevel.front()] > S-K*T and database[samelevel.front()] != 10000001){
					pq.push(pair <long long int, string> (S-K*T, M));
				}
				else if (database[samelevel.front()] == S-K*T){
					samelevel.push_back(M);
					samelevel.sort();
				}
				else{
					samelevel.push_front(M);
				}
			}
			else{
				pq.push(pair <long long int, string> (S-K*T, M));
			}
			
        }
        
        else if (Q == 2){
            cin >> T;
			if (pq.empty() and samelevel.empty()){
				cout << "doctor takes a break" << endl;
			}
			
			else{
				if (pq.empty() == false){
					while (database[pq.top().second] == 10000001){
						pq.pop();
						if (pq.empty()){
							break;
						}
					}
				}
				
				
				if (pq.empty() and samelevel.empty()){
				cout << "doctor takes a break" << endl;
				}
				
				else if (samelevel.empty() == false){
					while (database[samelevel.front()] == 10000001){
						samelevel.pop_front();
					}
					if (samelevel.empty() == false){
						cout << samelevel.front() << endl;
						database[samelevel.front()] = 10000001;
						samelevel.pop_front();
					}
					else if (pq.empty() and samelevel.empty()){
						cout << "doctor takes a break" << endl;
					}
					
					else{
						long long int temp = pq.top().first;
						samelevel.push_back(pq.top().second);
						pq.pop();
						while ((pq.top().first) == temp and pq.empty() == false){
							samelevel.push_back(pq.top().second);
							pq.pop();
							if (pq.empty() == true){
							break;
							}
						}
					
						samelevel.sort();
						cout << samelevel.front() << endl;
						database[samelevel.front()] = 10000001;
						samelevel.pop_front();
					}
					
				}
				
				else{
					long long int temp = pq.top().first;
					samelevel.push_back(pq.top().second);
					pq.pop();
					while ((pq.top().first) == temp and pq.empty() == false){
						samelevel.push_back(pq.top().second);
						pq.pop();
						if (pq.empty() == true){
						break;
						}
					}
					
					samelevel.sort();
					cout << samelevel.front() << endl;
					database[samelevel.front()] = 10000001;
					samelevel.pop_front();
				}
			}
		}
		
        else if (Q == 3){
            cin >> T >> M;
            database[M] = 10000001;
			if (samelevel.empty() == false){
				while (database[samelevel.front()] == 10000001){
					samelevel.pop_front();
				}
			}
			
        }
    }
    return 0;
}
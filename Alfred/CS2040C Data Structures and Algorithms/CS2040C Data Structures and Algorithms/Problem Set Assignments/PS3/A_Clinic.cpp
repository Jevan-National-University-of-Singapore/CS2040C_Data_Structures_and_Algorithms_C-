#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;


class patient{
public:
	string name;
	long long lvl;
};

class binary_heap{
private:
	vector <patient> V;
	unordered_map<string, long> p_index;
	long V_size;
	long parent(long i){return i/2;}
 	long left_child(long i){return i*2;}
  	long right_child(long i){return i*2+1;}

  	long obtain_index(string s){
  		return p_index[s];
  	}

  	void move_up(long i){ //from index i
  		p_index[V[i].name] = i;
  		if (i == 1){
  			return;
  		}
  		else if (V[i].lvl > V[parent(i)].lvl){
  			p_index[V[i].name] = parent(i); p_index[V[parent(i)].name] = i; //swapping the index (unordered map)
  			swap(V[i], V[parent(i)]); //swapping the objects in the binary heap
  			move_up(parent(i));
  		}
  		else if (V[i].lvl == V[parent(i)].lvl){
  			if (V[i].name < V[parent(i)].name){
  				p_index[V[i].name] = parent(i); p_index[V[parent(i)].name] = i; //swapping the index (unordered map)
  				swap(V[i], V[parent(i)]); //swapping the objects in the binary heap
  				move_up(parent(i));
  			}
  		}
  	}

  	void move_down(long i){ //from index i
  		p_index[V[i].name] = i;
  		if (left_child(i) <= V_size){
  			if (right_child(i) <= V_size){
  				if ((V[right_child(i)].lvl > V[left_child(i)].lvl) && (V[right_child(i)].lvl > V[i].lvl)){
  					p_index[V[i].name] = right_child(i); p_index[V[right_child(i)].name] = i;
  					swap(V[i], V[right_child(i)]);
  					move_down(right_child(i));
  				}
  				else if ((V[right_child(i)].lvl < V[left_child(i)].lvl) && (V[left_child(i)].lvl > V[i].lvl)){
  					p_index[V[i].name] = left_child(i); p_index[V[left_child(i)].name] = i;
  					swap(V[i], V[left_child(i)]);
  					move_down(left_child(i));
  				}
   				else if ((V[right_child(i)].lvl == V[left_child(i)].lvl) && (V[left_child(i)].lvl > V[i].lvl)){
  						if (V[left_child(i)].name < V[right_child(i)].name){
  							p_index[V[i].name] = left_child(i); p_index[V[left_child(i)].name] = i; //swapping the index (unordered map)
  							swap(V[i], V[left_child(i)]); //swapping the objects in the binary heap
  							move_down(left_child(i));
  						}
  						else{
  							p_index[V[i].name] = right_child(i); p_index[V[right_child(i)].name] = i; //swapping the index (unordered map)
  							swap(V[i], V[right_child(i)]); //swapping the objects in the binary heap
  							move_down(right_child(i));
  						}
  				}
  				else if (V[i].lvl == V[right_child(i)].lvl){
  					if (V[i].lvl == V[left_child(i)].lvl) {
  						if ((V[i].name > V[right_child(i)].name) && (V[i].name > V[left_child(i)].name)){
  							if (V[left_child(i)].name < V[right_child(i)].name){
  								p_index[V[i].name] = left_child(i); p_index[V[left_child(i)].name] = i; //swapping the index (unordered map)
  								swap(V[i], V[left_child(i)]); //swapping the objects in the binary heap
  								move_down(left_child(i));
  							}
  							else{
  								p_index[V[i].name] = right_child(i); p_index[V[right_child(i)].name] = i; //swapping the index (unordered map)
  								swap(V[i], V[right_child(i)]); //swapping the objects in the binary heap
  								move_down(right_child(i));
  							}
  						}
  						else if (V[i].name > V[right_child(i)].name){
  							p_index[V[i].name] = right_child(i); p_index[V[right_child(i)].name] = i; //swapping the index (unordered map)
  							swap(V[i], V[right_child(i)]); //swapping the objects in the binary heap
  							move_down(right_child(i));
  						}
  						else if (V[i].name > V[left_child(i)].name){
  							p_index[V[i].name] = left_child(i); p_index[V[left_child(i)].name] = i; //swapping the index (unordered map)
  							swap(V[i], V[left_child(i)]); //swapping the objects in the binary heap
  							move_down(left_child(i));
  						}
  					}
  					else if (V[i].lvl < V[left_child(i)].lvl){
  						p_index[V[i].name] = left_child(i); p_index[V[left_child(i)].name] = i; //swapping the index (unordered map)
  						swap(V[i], V[left_child(i)]); //swapping the objects in the binary heap
  						move_down(left_child(i));
  					}
  				}
  				else if ((V[i].lvl == V[left_child(i)].lvl) && (V[i].name > V[left_child(i)].name)){
  						p_index[V[i].name] = left_child(i); p_index[V[left_child(i)].name] = i; //swapping the index (unordered map)
  						swap(V[i], V[left_child(i)]); //swapping the objects in the binary heap
  						move_down(left_child(i));
  				}
  			}
  			else if (V[left_child(i)].lvl > V[i].lvl){
  				p_index[V[i].name] = left_child(i); p_index[V[left_child(i)].name] = i;
  				swap(V[i], V[left_child(i)]);
  				move_down(left_child(i));
  			}
  			else if (V[i].lvl == V[left_child(i)].lvl){
  				if (V[i].name > V[left_child(i)].name){
  					p_index[V[i].name] = left_child(i); p_index[V[left_child(i)].name] = i; //swapping the index (unordered map)
  					swap(V[i], V[left_child(i)]); //swapping the objects in the binary heap
  					move_down(left_child(i));
  				}
  			}
  		}
  	}

public:
  binary_heap() {
    patient nullp; nullp.name = ""; nullp.lvl = 0;
    V.clear();
    V.push_back(nullp);
    V_size = 0;
}

  void insert(patient x){
    V.push_back(x); V_size++;
    move_up(V_size); //V_size is index of inserted element
  }

  long find_patient_index(string s){
  	return obtain_index(s);
  }

  void remove(long i){
  	if (i == V_size){
  		V.pop_back(); V_size--;
  	}
  	else {
  		string temp = V[V_size].name;
  		p_index[V[i].name] = V_size; p_index[V[V_size].name] = i;
  		swap(V[i],V[V_size]);
  		V.pop_back(); V_size--; 
  		move_up(i); //check new element in index i if need to trickle up
  		long j = obtain_index(temp); move_down(j); //check new element in index i if need to trickle down
  	}
  }

  string get_max(){
  	return V[1].name;
  }

  bool is_empty(){ //returns true if binary heap is empty --> No patients
    return V_size == 0;
  }


};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	binary_heap pq;

	long N; long long K, S, T, P; int Q; string M;
	cin >> N >> K;
	while (N--){
		cin >> Q;
		if (Q == 1){ //adding patient with priority number
			cin >> T >> M >> S;
			P = S - K*T;
			patient x;
			x.name = M; x.lvl = P;
			pq.insert(x);
		}

		else if (Q == 2){ //removing (and printing) highest priority patient
			cin >> T;
			if (pq.is_empty() == true){
				cout << "doctor takes a break" << "\n";
			}
			else {
				cout << pq.get_max() << "\n";
				pq.remove(1);
			}
		}

		else if (Q == 3){ //removing patient
			cin >> T >> M;
			long i = pq.find_patient_index(M);
			pq.remove(i);
		}
	}

	return 0;
}
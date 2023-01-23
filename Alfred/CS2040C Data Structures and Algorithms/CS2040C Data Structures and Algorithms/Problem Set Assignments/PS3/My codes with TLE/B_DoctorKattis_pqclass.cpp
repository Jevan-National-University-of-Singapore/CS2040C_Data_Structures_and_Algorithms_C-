#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class cat{
public:
	string name;
	int infectlvl;
	int visitor_number;
};

class binary_heap{
private:
	vector <cat> V;
	unordered_map<string, int> catpos;
	int V_size;
	int parent(int i){return i/2;}
 	int left_child(int i){return i*2;}
  	int right_child(int i){return i*2+1;}

  	int obtain_index(string s){
  		return catpos[s];
  	}

  	void move_up(int i){ //from index i
  		catpos[V[i].name] = i;
  		if (i == 1){
  			return;
  		}
  		else if (V[i].infectlvl > V[parent(i)].infectlvl){
  			catpos[V[i].name] = parent(i); catpos[V[parent(i)].name] = i; //swapping the index (unordered map)
  			swap(V[i], V[parent(i)]); //swapping the cat objects in the binary heap
  			move_up(parent(i));
  		}
  	}

  	void move_down(int i){ //from index i
  		catpos[V[i].name] = i;
  		if (left_child(i) <= V_size){
  			if ((right_child(i) <= V_size) && (V[right_child(i)].infectlvl > V[left_child(i)].infectlvl) && (V[right_child(i)].infectlvl > V[i].infectlvl)){
  				catpos[V[i].name] = right_child(i); catpos[V[right_child(i)].name] = i;
  				swap(V[i], V[right_child(i)]);
  				move_down(right_child(i));
  			}
  			else if (V[left_child(i)].infectlvl > V[i].infectlvl){
  				catpos[V[i].name] = left_child(i); catpos[V[left_child(i)].name] = i;
  				swap(V[i], V[left_child(i)]);
  				move_down(left_child(i));
  			}
  		}
  	}
public:
  binary_heap() {
    cat nullcat; nullcat.name = ""; nullcat.infectlvl = 0;
    V.clear();
    V.push_back(nullcat);
    V_size = 0;
}

  void insert(cat x){
    V.push_back(x); V_size++;
    move_up(V_size); //V_size is index of inserted element
  }

  int find_cat_index(string s){
  	return obtain_index(s);
  }

  void changelvl(int i, int x){
  	V[i].infectlvl += x;
  	if (V[i].infectlvl > 100)
  		V[i].infectlvl = 100;
  	move_up(i);
  }
  void remove(int i){
  	V[i].infectlvl = 0;
  	if (i == V_size){
  		V.pop_back(); V_size--;
  	}
  	else {
  		string temp = V[V_size].name;
  		catpos[V[i].name] = V_size; catpos[V[V_size].name] = i;
  		swap(V[i],V[V_size]);
  		V.pop_back(); V_size--; 
  		move_up(i); //check new element in index i if need to trickle up
  		int j = obtain_index(temp); move_down(j); //check new element in index i if need to trickle down
  	}
  }

//Would make it faster if i can implement this checkmax when moveup/movedown already.
  void check_max(int i){ //for query, to get cat's name
  	if (left_child(i) <= V_size){
      int a = V[1].visitor_number; int l = V[left_child(i)].visitor_number;
      if (V[1].infectlvl == V[left_child(i)].infectlvl){
  		  if (a > l){
  			 catpos[V[1].name] = left_child(i); catpos[V[left_child(i)].name] = 1;
  			 swap(V[1], V[left_child(i)]);
  		  }
  		  check_max(left_child(i));
      }
      if (right_child(i) <= V_size){
        a = V[1].visitor_number; int r = V[right_child(i)].visitor_number;
        if (V[1].infectlvl == V[right_child(i)].infectlvl){
  		    if (a > r){
  			   catpos[V[1].name] = right_child(i); catpos[V[right_child(i)].name] = 1;
  			   swap(V[1], V[right_child(i)]);
  		    }
  		    check_max(right_child(i));
        }
      }
  	}
  }

  string get_max(){
  	return V[1].name;
  }

  bool is_empty(){ //returns true if binary heap is empty --> No cats
    return V_size == 0;
  }


// //for checking
//   // int get_size(){
//   // 	return V_size;
//   // }

//   string print_all(){
//   	string combinedstring = "";
//   	for (int i = 0; i < V.size(); i++){
//   		combinedstring += V[i].name += to_string(V[i].infectlvl);
//   	}
//   	return combinedstring;
//   }

};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	binary_heap pq; //priority queue to store the cat's data

	string name; int infectlvl, inc_infect; int cat_counter = 0;
	// cout << pq.print_all() << "\n"; //for checking

	long N; cin >> N;
	while (N--) {
		int cmd; cin >> cmd;
		if (cmd == 0){
			cin >> name >> infectlvl;
			cat x;
			x.name = name; x.infectlvl = infectlvl;
			cat_counter++; x.visitor_number = cat_counter;
			pq.insert(x); 
			// int i = pq.find_cat_index(name); //for checking
			// cout << i; //for checking
			// cout << pq.print_all() << "\n"; //for checking
		}

		else if (cmd == 1){
			cin >> name; cin >> inc_infect;
			int i = pq.find_cat_index(name);
			// cout << i; //for checking
			pq.changelvl(i, inc_infect);
			// cout << pq.print_all() << "\n"; //for checking
		}

		else if (cmd == 2){
			cin >> name;
			int i = pq.find_cat_index(name);
			// cout << i; //for checking
			pq.remove(i);
			// cout << pq.print_all() << "\n"; //for checking
		}

		else if (cmd == 3){
			if (pq.is_empty() == true)
				cout << "The clinic is empty" << "\n";
			else {
				pq.check_max(1);
				// cout << pq.print_all() << "\n"; //for checking
				cout << pq.get_max() << "\n";
			}
		}

	}
	return 0;
}
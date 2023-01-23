#include <iostream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <map> 
#include <iomanip>
 
using namespace std; 

class Prescription {
    public:
        double __d;
        double __k;
        char __s;
};


class Compare{
    public:
        bool operator () (Prescription a, Prescription b){
            if (a.__d < b.__d){
                return false;
            }
            if (a.__d == b.__d && a.__k < b.__k){
                return false;
            }
            return true;
        }
};
 
int main(){ 
    long long n; 
    cin >> n; 
    long long T; 
    cin >> T; 
    double counterR=0; 
    double counterS=0; 
    double R=0; 
    double S=0; 
    priority_queue<Prescription, vector<Prescription>, Compare>remote_prescriptions;
    priority_queue<Prescription, vector<Prescription>, Compare>in_store_prescriptions;
    priority_queue<double, vector<double>, greater<double>> technicians_finish_time;
    for (long long i = 0; i<n; i++){ 
        Prescription new_prescription;
        cin >> new_prescription.__d;
        cin >> new_prescription.__s; 
        cin >> new_prescription.__k; 
        if (new_prescription.__s == 'S'){ 
            in_store_prescriptions.push(new_prescription);
        } else {
            remote_prescriptions.push(new_prescription);
        }
    }

    for (long long i = 0; i < T; i++){
        technicians_finish_time.push(0);
    }
    
    for (long long i = 0; i < n; i++){
        double start_fill_time_r = 0;
        double time_to_fill_r = 0;
        double start_fill_time_s = 0;
        double time_to_fill_s = 0;
        double tech_finish = technicians_finish_time.top();
        if (!in_store_prescriptions.empty()){
			start_fill_time_s = in_store_prescriptions.top().__d;
			time_to_fill_s = in_store_prescriptions.top().__d;
		}
        if (!remote_prescriptions.empty()){
			start_fill_time_r = remote_prescriptions.top().__d;
			time_to_fill_r = remote_prescriptions.top().__d;
		}

        if ((time_to_fill_s <= tech_finish) && time_to_fill_s != 0){
			counterS++;
			S += time_to_fill_s + tech_finish - start_fill_time_s;
			in_store_prescriptions.pop();
            technicians_finish_time.pop();
			technicians_finish_time.push(tech_finish + time_to_fill_s);
		}else if (((start_fill_time_s <= start_fill_time_r) && time_to_fill_s != 0) || time_to_fill_r == 0){ 
            counterS++;
            S += time_to_fill_s;
			in_store_prescriptions.pop();
            technicians_finish_time.pop();
            technicians_finish_time.push(start_fill_time_s + time_to_fill_s);
		}else if (start_fill_time_r >= tech_finish){
            counterR++;
            R += time_to_fill_r;
            remote_prescriptions.pop();
            technicians_finish_time.pop();
			technicians_finish_time.push(start_fill_time_r + time_to_fill_r);
		}else{ 
			counterR++;
			R += time_to_fill_r + tech_finish - start_fill_time_r;
			remote_prescriptions.pop();
            technicians_finish_time.pop();
            technicians_finish_time.push(tech_finish + time_to_fill_r);
		}
		
	}
       /* if (!in_store_prescriptions.empty()){ 
            if (in_store_prescriptions.top().__d <= tech_finish){
                technicians_finish_time.pop();
                technicians_finish_time.push(tech_finish + in_store_prescriptions.top().__k);
                counterS++;
                S += in_store_prescriptions.top().__k + tech_finish - in_store_prescriptions.top().__d;
                in_store_prescriptions.pop();
            } else if (!remote_prescriptions.empty()){
                if  (in_store_prescriptions.top().__d <= remote_prescriptions.top().__d){
                    technicians_finish_time.pop();
                    technicians_finish_time.push(in_store_prescriptions.top().__d + in_store_prescriptions.top().__k);
                    counterS++;
                    S += in_store_prescriptions.top().__k;
                    in_store_prescriptions.pop();
                } else if (remote_prescriptions.top().__d > tech_finish) {
                    technicians_finish_time.pop();
                    technicians_finish_time.push(remote_prescriptions.top().__d + remote_prescriptions.top().__k);
                    counterR++;
                    R += remote_prescriptions.top().__k;
                    remote_prescriptions.pop();
                } else {
                    technicians_finish_time.pop();
                    technicians_finish_time.push(tech_finish + remote_prescriptions.top().__k);
                    counterR++;
                    R += remote_prescriptions.top().__k + tech_finish - remote_prescriptions.top().__d;
                    remote_prescriptions.pop();
                }
            } else {
                technicians_finish_time.pop();
                technicians_finish_time.push(in_store_prescriptions.top().__d + in_store_prescriptions.top().__k);
                counterS++;
                S += remote_prescriptions.top().__k;
                in_store_prescriptions.pop();
            }
		} else if (tech_finish <= remote_prescriptions.top().__d){
			technicians_finish_time.pop();
			technicians_finish_time.push(remote_prescriptions.top().__d + remote_prescriptions.top().__k);
			counterR++;
			R += remote_prescriptions.top().__k;
			remote_prescriptions.pop();
		}else {
            technicians_finish_time.pop();
			technicians_finish_time.push(tech_finish + remote_prescriptions.top().__k);
			counterR++;
			R += remote_prescriptions.top().__k + tech_finish - remote_prescriptions.top().__d;
			remote_prescriptions.pop();
		}
        
    }*/
    if (counterS == 0){
		cout << 0.000000;
	} else{
		cout << fixed <<  setprecision(6) << S/counterS;
	}

    cout << " ";
	
	if (counterR == 0){
		cout << 0.000000;
	} else{
		cout << R / counterR;
	}
    

 }
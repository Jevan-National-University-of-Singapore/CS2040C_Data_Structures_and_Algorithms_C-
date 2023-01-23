#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main(){
    map<string, long long> fer;
    string name = "test";
    long long num = 10;

    fer.insert({name, num});
            /*if (!in_store_prescriptions.empty()){
			start_fill_time_s = in_store_prescriptions.top().__d;
			time_to_fill_s = in_store_prescriptions.top().__d;
		}
        if (!remote_prescriptions.empty()){
			start_fill_time_r = remote_prescriptions.top().__d;
			time_to_fill_r = remote_prescriptions.top().__d;
		}

        if ((time_to_fill_s <= technicians_finish_time.top()) && time_to_fill_s != 0){ // (1) worker not available by next s
			technicians_finish_time.pop();
			technicians_finish_time.push(technicians_finish_time.top() + time_to_fill_s);
			counterS++;
			S += time_to_fill_s + technicians_finish_time.top() - start_fill_time_s;
			in_store_prescriptions.pop();
		}else if (((start_fill_time_s <= start_fill_time_r) && time_to_fill_s != 0) || time_to_fill_r == 0){ //(2) worker available, s <= r
            technicians_finish_time.pop();
            technicians_finish_time.push(start_fill_time_s + time_to_fill_s);
            counterS++;
            S += time_to_fill_s;
			in_store_prescriptions.pop();
		}else if (start_fill_time_r >= technicians_finish_time.top()){ //(3) worker available, r < s
			technicians_finish_time.pop();
			technicians_finish_time.push(start_fill_time_r + time_to_fill_r);
            counterR++;
            R += time_to_fill_r;
            remote_prescriptions.pop();
		}else{ //(4) worker not available by next r, but available for r before s 
            technicians_finish_time.pop();
            technicians_finish_time.push(technicians_finish_time)
			time_taken = z_r + w - x_r;
			Workers_ready.pop();
			Workers_ready.push(w + z_r);
			R[0] += 1;
			R[1] += time_taken;
			pq_r.pop();
		}
		// cout << S[0] << ' '<< S[1]<< ' ' << R[0] <<' ' << R[1] << endl;
	}*/

}
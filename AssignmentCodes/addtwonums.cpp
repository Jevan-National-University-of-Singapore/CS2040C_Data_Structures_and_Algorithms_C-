#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long tens = 0;
        long long num_1 = 0;
        while(l1 -> next){
            num_1 += l1 -> val*tens;
            l1 = l1->next;
            tens *= 10;
        }
        tens = 0;
        long long num_2 = 0;
        while(l2 -> next){
            num_2 += l2 -> val*tens;
            l2 = l2->next;
            tens *= 10;
        }
        long long sum = num_1 +num_2;
        if (sum == 0){
            ListNode results(0);
            ListNode *results_pointer = &results;
            return results_pointer;
        }
        vector<int>sum_vector;
        while (sum){
            sum_vector.push_back(sum%10);
            sum /= 10;
        };
        ListNode next {
            sum_vector.front()
        };
        for (vector<int>::const_iterator it = sum_vector.begin()+1; it != sum_vector.end(); it++){
            ListNode *next_pointer = &next;
            ListNode node(*it,next_pointer);
            next = node;
        }
        ListNode *next_pointer = &next;
        return next_pointer;
    }
};

int main(){
    
}
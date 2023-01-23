#include <bits/stdc++.h>
using namespace std;

// https://visualgo.net/en/list?slide=3-1
struct Vertex { // we can use either C struct or C++/Python/Java class
  int item; // the data is stored here, an integer in this example
  Vertex* next; // this pointer tells us where is the next vertex
};

class SLL {
private:
  Vertex* head;
  Vertex* tail; // show how to maintain tail pointer so that InsertAfterTail is O(1)
public:
  SLL() {
    head = NULL;
    tail = NULL;
  }
  void InsertAtHead(int v) {
    // https://visualgo.net/en/list?slide=3-8
    Vertex* vtx = new Vertex(); // create new vertex vtx from item v
    vtx->item = v;
    vtx->next = head; // link this new vertex to the (old) head vertex
    if (head == NULL) tail = vtx; // :O
    head = vtx; // the new vertex becomes the new head
  }
  void InsertAfterTail(int v) {
    if (head == NULL)
      InsertAtHead(v);
    else {
      // Vertex* ptr = head; // we have to start from head
      // while (ptr->next != NULL) // while not tail, O(N)
      //   ptr = ptr->next; // the pointers are pointing to the higher index
      // // now ptr is tail
      Vertex* vtx = new Vertex(); // create new vertex vtx from item v
      vtx->item = v;
      tail->next = vtx; // link tail to this new vertex, O(1)
      tail = vtx; // now update tail, O(1)
    }
  }
  int GetHead() {
    if (head == NULL) return -1; // avoid crashing when SLL is empty
    return head->item;
  }
  int GetTail() {
    if (tail == NULL) return -1; // avoid crashing when SLL is empty (if tail == NULL, then head must also be NULL)
    return tail->item;
  }
  void DeleteHead() {
    // https://visualgo.net/en/list?slide=3-15   
    if (head == NULL) return; // avoid crashing when SLL is empty
    Vertex* temp = head; // so we can delete it later
    head = head->next; // book keeping, update the head pointer
    delete temp; // which is the old head
    if (head == NULL) tail = NULL; // another corner case
  }
  void printDummy() {
    cout << "MyStack (or MyQueue) should not be able to use this or any other SLL operations that are not related to Stack/Queue operations\n";
  }
};

// live demo to extend this thing (which is actually already a Stack) into a new class MyStack
class MyStack : SLL { // a proper subset of SLL (as it has other stuffs like 'printDummy', 'InsertAfterTail', 'GetTail'), touching only operations that involves head element
public:
  MyStack() { } // nothing
  void push(int v) { InsertAtHead(v); } // at head (causing the ordering to be LIFO - Last In First Out)
  void pop() { DeleteHead(); }
  int top() { return GetHead(); }
};

// live demo to extend this thing (which needs InsertAfterTail) into a new class MyQueue, starting with the 'slow' O(N) InsertAfterTail first...
class MyQueue : SLL { // another proper subset of SLL, touching only operations that involves head (for dequeue) and tail (for enqueue) element
public:
  MyQueue() { }
  void push(int v) { InsertAfterTail(v); } // after tail (causing the ordering to be FIFO - First In First Out)
  void pop() { DeleteHead(); }
  int front() { return GetHead(); }
  int back() { return GetTail(); }
};

int main() {
  MyStack ms;
  // stack<int> ms; // again, why reinvent the wheel :O..., commenting the previous line (MyStack) and using this line (std::stack) also works
  ms.push(5);
  ms.push(2);
  ms.push(7);
  cout << ms.top() << "\n"; // output 7 as the SLL is 7 (head)->2->5 now
  ms.pop();
  cout << ms.top() << "\n"; // output 2 as the SLL is 2 (head)->5 now
  // cout << ms.printDummy() << "\n"; // cannot access
  ms.pop();
  cout << ms.top() << "\n"; // output 5 as the SLL is 5 (head)
  ms.pop();
  cout << ms.top() << "\n"; // -1 (empty SLL), already safe-guarded, won't crash

  cout << "-------------------------\n";

  MyQueue mq;
  // queue<int> mq; // again, why reinvent the wheel :O..., commenting the previous line (MyQueue) and using this line (std::queue) also works
  mq.push(5);
  mq.push(2);
  mq.push(7);
  cout << mq.front() << " --- " << mq.back() << "\n"; // SLL 5 (head)->2->7 ("tail", because I don't remember tail in the implementation above)
  mq.pop();
  cout << mq.front() << " --- " << mq.back() << "\n"; // SLL 2 (head)->7 ("tail", because I don't remember tail in the implementation above)
  // cout << mq.printDummy() << "\n"; // cannot access
  mq.pop();
  cout << mq.front() << " --- " << mq.back() << "\n"; // output 7 as the SLL is 7 (head/and also tail)
  mq.pop();
  cout << mq.front() << " --- " << mq.back() << "\n"; // -1 (empty SLL), already safe-guarded, won't crash

  return 0;
}

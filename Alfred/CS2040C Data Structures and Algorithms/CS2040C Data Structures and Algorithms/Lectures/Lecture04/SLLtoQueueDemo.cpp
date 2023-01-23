#include <bits/stdc++.h>
using namespace std;

// https://visualgo.net/en/list?slide=3-1
struct Vertex { // we can use either C struct or C++/Java class
  int item; // the data is stored here, an integer in this example
  Vertex* next; // this pointer tells us where is the next vertex
};

class SLL {
private:
  Vertex* head;
  Vertex* tail; // challenge to the rest: fix this implementation so that InsertAfterTail is REALLY O(1)
public:
  SLL() {
    head = NULL;
  }
  void InsertAtHead(int v) {
    // https://visualgo.net/en/list?slide=3-8
    Vertex* vtx = new Vertex(); // create new vertex vtx from item v
    vtx->item = v;
    vtx->next = head; // link this new vertex to the (old) head vertex
    head = vtx; // the new vertex becomes the new head
  }
  void InsertAfterTail(int v) {
    if (head == NULL)
      InsertAtHead(v);
    else {
      Vertex* ptr = head; // we have to start from head
      while (ptr->next != NULL) // while not tail, O(N)
        ptr = ptr->next; // the pointers are pointing to the higher index
      // now ptr is tail
      Vertex* vtx = new Vertex(); // create new vertex vtx from item v
      vtx->item = v;
      ptr->next = vtx; // link tail to this new vertex
    }
  }
  int GetHead() {
    if (head == NULL) return -1; // avoid crashing when SLL is empty
    return head->item;
  }
  void DeleteHead() {
    // https://visualgo.net/en/list?slide=3-15   
    if (head == NULL) return; // avoid crashing when SLL is empty
    Vertex* temp = head; // so we can delete it later
    head = head->next; // book keeping, update the head pointer
    delete temp; // which is the old head
  }
};

// live demo to extend SLL with just head pointer to a new class MyQueue
class MyQueue : SLL {
public:
  MyQueue() {}
  void enqueue(int v) { InsertAfterTail(v); } // quite slow if we *only* maintain head pointer
  int front() { return GetHead(); }
  void dequeue() { DeleteHead(); }
};

int main() {
  MyQueue q;
  // experiment with this baseline code to familiarise yourself with the very basic idea of Linked List data structure
  q.enqueue(5);
  q.enqueue(2);
  q.enqueue(7);
  cout << q.front() << "\n"; // output 5 as the SLL is 5 (head)->2->7 (tail) now
  q.dequeue();
  cout << q.front() << "\n"; // output 2 as the SLL is 2 (head)->7 (tail) now

  return 0;
}

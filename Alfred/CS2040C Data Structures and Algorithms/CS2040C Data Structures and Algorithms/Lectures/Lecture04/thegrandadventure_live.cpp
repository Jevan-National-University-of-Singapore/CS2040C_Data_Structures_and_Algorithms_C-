// there is a one character bug in this code, submitting it verbatim will cause wrong answer

#include <bits/stdc++.h>
using namespace std;

// https://visualgo.net/en/list?slide=3-1
struct Vertex { // we can use either C struct or C++/Java class
  char item; // the data is stored here, an integer in this example
  Vertex* next; // this pointer tells us where is the next vertex
};

class SLL {
private:
  Vertex* head;
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
  char GetHead() {
    if (head == NULL) return '@'; // avoid crashing when SLL is empty
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

// live demo to extend SLL with just head pointer (which is actually a Stack) to a new class MyStack
class MyStack : SLL {
private:
public:
  MyStack() {}
  void push(char v) {
    InsertAtHead(v);
  }
  char peek() {
    return GetHead();
  }
  void pop() {
    DeleteHead();
  }
  bool empty() {
    return GetHead() == '@';
  }
};

int main() {
  int n; cin >> n;
  while (n--) {
    string a; cin >> a;
    // stack<char> backpack; // C++ STL std::stack, too "easy"
    MyStack backpack;
    bool success = true;
    for (auto &c : a) { // for each character in string a
      if (c == '.') continue; // is a Ground (nothing)
      switch (c) {
        case '$':
        case '|':
        case '*': // either '$', '|', or '*' will hit line 66-67
          backpack.push(c);
          break;
        case 't':
        case 'j':
        case 'b': // one of the villain: 't' wants '|', 'j' wants '*', 'b' wants '$'
          char demand = '*'; // assume 't' wants '|'
          if (c == 'j') demand = '*';
          else if (c == 'b') demand = '$';
          // check backpack
          while (!backpack.empty() && (backpack.peek() != demand)) // apparently "not necessary" to do this :O..., maybe the test case is weak?
            backpack.pop();
          if (backpack.empty())
            success = false;
          else
            backpack.pop();
          break;
      }
    }
    success &= backpack.empty(); // reach the end with empty stack
    cout << (success ? "YES\n" : "NO\n");
  }
  return 0;
}

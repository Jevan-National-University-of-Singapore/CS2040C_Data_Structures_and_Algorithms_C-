import java.io.*;

// live demo to extend this thing (which is actually a Stack) to a new class MyStack later

class SLLDemo {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    SLL l = new SLL();
    // experiment with this baseline code to familiarise yourself with the very basic idea of Linked List data structure
    l.InsertAtHead(5);
    l.InsertAtHead(2);
    l.InsertAtHead(7);
    pw.println(l.GetHead()); // output 7 as the SLL is 7 (head)->2->5 now
    l.DeleteHead();
    pw.println(l.GetHead()); // output 2 as the SLL is 2 (head)->5 now

    pw.close();
  }
}


// https://visualgo.net/en/list?slide=3-1
class Vertex { // we can use either C struct or C++/Java class
  int item; // the data is stored here, an integer in this example
  Vertex next; // this pointer tells us where is the next vertex
}

class SLL {
  protected Vertex head;

  // https://visualgo.net/en/list?slide=3-5
  protected Vertex Get(int i) { // returns the vertex
    Vertex ptr = head; // we have to start from head
    for (int k = 0; k < i; k++) // advance forward i time(s)
      ptr = ptr.next; // the pointers are pointing to the higher index
    return ptr;
  }

  public SLL() {
    head = null;
  }

  public void InsertAtHead(int v) {
    // https://visualgo.net/en/list?slide=3-8
    Vertex vtx = new Vertex(); // create new vertex vtx from item v
    vtx.item = v;
    vtx.next = head; // link this new vertex to the (old) head vertex
    head = vtx; // the new vertex becomes the new head
  }

  public int GetHead() {
    if (head == null) return -1; // avoid crashing when SLL is empty
    return Get(0).item;
  }

  public void DeleteHead() {
    // https://visualgo.net/en/list?slide=3-15   
    if (head == null) return; // avoid crashing when SLL is empty
    Vertex temp = head; // so we can delete it later
    head = head.next; // book keeping, update the head pointer
    temp = null; // which is the old head
  }
}

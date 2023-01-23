// first, you need to already compile BSTDemo.java so that BSTVertex.class and BST.class are there
// then, you can run this AVLDemo



import java.util.*;

class AVL extends BST { // an example of Java inheritance
  public AVL() { root = null; }

  private int h(BSTVertex T) { return T == null ? -1 : T.height; }

  protected BSTVertex rotateLeft(BSTVertex T) {
    // T must have a right child

    BSTVertex w = T.right;
    w.parent = T.parent;
    T.parent = w;
    T.right = w.left;
    if (w.left != null) w.left.parent = T;
    w.left = T;

    T.height = Math.max(h(T.left), h(T.right)) + 1;
    w.height = Math.max(h(w.left), h(w.right)) + 1;

    return w;
  }

  protected BSTVertex rotateRight(BSTVertex T) {
    // T must have a left child

    BSTVertex w = T.left;
    w.parent = T.parent;
    T.parent = w;
    T.left = w.right;
    if (w.right != null) w.right.parent = T;
    w.right = T;

    T.height = Math.max(h(T.left), h(T.right)) + 1;
    w.height = Math.max(h(w.left), h(w.right)) + 1;

    return w;
  }

  protected BSTVertex insert(BSTVertex T, int v) {
    if (T == null) return new BSTVertex(v);          // insertion point is found

    if (T.key < v) {                                      // search to the right
      T.right = insert(T.right, v);
      T.right.parent = T;
    }
    else {                                                 // search to the left
      T.left = insert(T.left, v);
      T.left.parent = T;
    }

    int balance = h(T.left) - h(T.right);
    if (balance == 2) { // left heavy
      int balance2 = h(T.left.left) - h(T.left.right);
      if (balance2 == 1) {
        T = rotateRight(T);
      }
      else { // -1
        T.left = rotateLeft(T.left);
        T = rotateRight(T);
      }
    }
    else if (balance == -2) { // right heavy
      int balance2 = h(T.right.left) - h(T.right.right);
      if (balance2 == -1)
        T = rotateLeft(T);
      else { // 1
        T.right = rotateRight(T.right);
        T = rotateLeft(T);
      }
    }

    T.height = Math.max(h(T.left), h(T.right)) + 1;
    return T;                                          // return the updated AVL
  }

  protected BSTVertex delete(BSTVertex T, int v) {
    if (T == null)  return T;              // cannot find the item to be deleted

    if (T.key == v) {                          // this is the node to be deleted
      if (T.left == null && T.right == null)                   // this is a leaf
        T = null;                                      // simply erase this node
      else if (T.left == null && T.right != null) {   // only one child at right
        BSTVertex temp = T;
        T.right.parent = T.parent;
        T = T.right;                                                 // bypass T
        temp = null;
      }
      else if (T.left != null && T.right == null) {    // only one child at left
        BSTVertex temp = T;
        T.left.parent = T.parent;
        T = T.left;                                                  // bypass T
        temp = null;
      }
      else {                                 // has two children, find successor
        int successorV = successor(v);
        T.key = successorV;         // replace this key with the successor's key
        T.right = delete(T.right, successorV);      // delete the old successorV
      }
    }
    else if (T.key < v)                                   // search to the right
      T.right = delete(T.right, v);
    else                                                   // search to the left
      T.left = delete(T.left, v);

    if (T != null) {               // similar as insertion code except this line
      int balance = h(T.left) - h(T.right);
      if (balance == 2) { // left heavy
        int balance2 = h(T.left.left) - h(T.left.right);
        if (balance2 == 1) {
          T = rotateRight(T);
        }
        else { // -1
          T.left = rotateLeft(T.left);
          T = rotateRight(T);
        }
      }
      else if (balance == -2) { // right heavy
        int balance2 = h(T.right.left) - h(T.right.right);
        if (balance2 == -1)
          T = rotateLeft(T);
        else { // 1
          T.right = rotateRight(T.right);
          T = rotateLeft(T);
        }
      }

      T.height = Math.max(h(T.left), h(T.right)) + 1;
    }

    return T;                                          // return the updated BST
  }
}



class AVLDemo {
  public static void main(String[] args) throws Exception {
    // let's contrast and compare
    BST T = new BST();                                           // an empty BST
    AVL A = new AVL();                                           // an empty AVL

    int n = 12;
    int[] arr = new int[]{15, 32, 100, 6, 23, 4, 7, 71, 5, 50, 3, 1};
    for (int i = 0; i < n; i++) {
      T.insert(arr[i]);
      A.insert(arr[i]);
    }

    // Example of Java polymorphism: method getHeight() returns different value
    System.out.println(T.getHeight());                         // 4, taller tree
    System.out.println(A.getHeight());                        // 3, shorter tree

    // Another Java polymorphism: method inorder() returns similar value
    T.inorder();                      // The BST: 1 3 4 5 6 7 15 23 32 50 71 100
    A.inorder();                      // The AVL: 1 3 4 5 6 7 15 23 32 50 71 100

    System.out.println("---");
    System.out.println(A.search(71));                               // found, 71
    System.out.println(A.search(7));                                 // found, 7
    System.out.println(A.search(22));                           // not found, -1

    System.out.println(A.findMin());                                        // 1
    System.out.println(A.findMax());                                      // 100

    System.out.println("---");
    System.out.println(A.successor(1));                                     // 3
    System.out.println(A.successor(3));                                     // 4
    System.out.println(A.successor(4));                                     // 5
    System.out.println(A.successor(5));                                     // 6
    System.out.println(A.successor(6));                                     // 7
    System.out.println(A.successor(7));                                    // 15
    System.out.println(A.successor(15));                                   // 23
    System.out.println(A.successor(23));                                   // 32
    System.out.println(A.successor(32));                                   // 50
    System.out.println(A.successor(50));                                   // 71
    System.out.println(A.successor(71));                                  // 100
    System.out.println(A.successor(100));                                  // -1

    System.out.println("---");
    System.out.println(A.predecessor(1));                                  // -1
    System.out.println(A.predecessor(3));                                   // 1
    System.out.println(A.predecessor(4));                                   // 3
    System.out.println(A.predecessor(5));                                   // 4
    System.out.println(A.predecessor(6));                                   // 5
    System.out.println(A.predecessor(7));                                   // 6
    System.out.println(A.predecessor(15));                                  // 7
    System.out.println(A.predecessor(23));                                 // 15
    System.out.println(A.predecessor(32));                                 // 23
    System.out.println(A.predecessor(50));                                 // 32
    System.out.println(A.predecessor(71));                                 // 50
    System.out.println(A.predecessor(100));                                // 71

    // deletion demo
    System.out.println("---");
    System.out.print("Current BST/AVL:");
    A.inorder();

    int[] deletionorder = new int[]{23, 100, 32, 71, 50, 7, 5, 1, 3, 6, 15, 4};
    for (int i = 0; i < n; i++) {
      System.out.println("Deleting: " + deletionorder[i]);

      A.delete(deletionorder[i]);
      System.out.print("AVL, height: " + A.getHeight() + ", inorder traversal: ");
      A.inorder();

      T.delete(deletionorder[i]);
      System.out.print("BST, height: " + T.getHeight() + ", inorder traversal: "); // equal or taller than A.getHeight()
      T.inorder(); // should be the same as A.inorder()
    }
  }
}

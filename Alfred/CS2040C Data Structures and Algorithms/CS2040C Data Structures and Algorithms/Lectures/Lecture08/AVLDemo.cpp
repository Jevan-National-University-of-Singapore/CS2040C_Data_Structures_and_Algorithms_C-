// first, you need to comment out the int main() inside BSTDemo.cpp (so that the int main() in AVLDemo is used instead, otherwise you will have compilation error involving duplicate int main()s)
// then compile this AVLDemo.cpp file and run it

#include <bits/stdc++.h>
#include "BSTDemo.cpp" // make sure this file is in the same folder and its main method commented out
using namespace std;

class AVL : public BST { // another example of C++ inheritance
private:
  int h(BSTVertex* T) { return T == NULL ? -1 : T->height; }

  BSTVertex* rotateLeft(BSTVertex* T) {
    // T must have a right child

    BSTVertex* w = T->right;
    w->parent = T->parent;
    T->parent = w;
    T->right = w->left;
    if (w->left != NULL) w->left->parent = T;
    w->left = T;

    T->height = max(h(T->left), h(T->right)) + 1;
    w->height = max(h(w->left), h(w->right)) + 1;

    return w;
  }

  BSTVertex* rotateRight(BSTVertex* T) {
    // T must have a left child

    BSTVertex* w = T->left;
    w->parent = T->parent;
    T->parent = w;
    T->left = w->right;
    if (w->right != NULL) w->right->parent = T;
    w->right = T;

    T->height = max(h(T->left), h(T->right)) + 1;
    w->height = max(h(w->left), h(w->right)) + 1;

    return w;
  }

  BSTVertex* insert(BSTVertex* T, int v) {       // override insert in BST class
    if (T == NULL) {                             // insertion point is found
      T = new BSTVertex;
      T->key = v;
      T->parent = T->left = T->right = NULL;
      T->height = 0; // will be used in AVL lecture
    }
    else if (T->key < v) {                       // search to the right
      T->right = insert(T->right, v);
      T->right->parent = T;
    }
    else {                                       // search to the left
      T->left = insert(T->left, v);
      T->left->parent = T;
    }

    int balance = h(T->left) - h(T->right);
    if (balance == 2) { // left heavy
      int balance2 = h(T->left->left) - h(T->left->right);
      if (balance2 == 1) {
        T = rotateRight(T);
      }
      else { // -1
        T->left = rotateLeft(T->left);
        T = rotateRight(T);
      }
    }
    else if (balance == -2) { // right heavy
      int balance2 = h(T->right->left) - h(T->right->right);
      if (balance2 == -1)
        T = rotateLeft(T);
      else { // 1
        T->right = rotateRight(T->right);
        T = rotateLeft(T);
      }
    }

    T->height = max(h(T->left), h(T->right)) + 1;
    return T;                                    // return the updated AVL
  }

  BSTVertex* remove(BSTVertex* T, int v) {
    if (T == NULL)  return T;                    // cannot find the item

    if (T->key == v) {                           // the node to be deleted
      if (T->left == NULL && T->right == NULL)   // this is a leaf
        T = NULL;                                // simply erase this node
      else if (T->left == NULL && T->right != NULL) { // only one child at right
        BSTVertex* temp = T;
        T->right->parent = T->parent;
        T = T->right;                            // bypass T
        temp = NULL;
      }
      else if (T->left != NULL && T->right == NULL) { // only one child at left
        BSTVertex* temp = T;
        T->left->parent = T->parent;
        T = T->left;                             // bypass T
        temp = NULL;
      }
      else {                                     // find successor
        int successorV = successor(v);
        T->key = successorV;                     // replace with successorV
        T->right = remove(T->right, successorV); // delete the old successorV
      }
    }
    else if (T->key < v)                         // search to the right
      T->right = remove(T->right, v);
    else                                         // search to the left
      T->left = remove(T->left, v);

    if (T != NULL) {               // similar as insertion code except this line
      int balance = h(T->left) - h(T->right);
      if (balance == 2) { // left heavy
        int balance2 = h(T->left->left) - h(T->left->right);
        if (balance2 == 1) {
          T = rotateRight(T);
        }
        else { // -1
          T->left = rotateLeft(T->left);
          T = rotateRight(T);
        }
      }
      else if (balance == -2) { // right heavy
        int balance2 = h(T->right->left) - h(T->right->right);
        if (balance2 == -1)
          T = rotateLeft(T);
        else { // 1
          T->right = rotateRight(T->right);
          T = rotateLeft(T);
        }
      }

      T->height = max(h(T->left), h(T->right)) + 1;
    }

    return T;                                    // return the updated BST
  }

public:
  AVL() { root = NULL; }

  void insert(int v) { root = insert(root, v); }

  void remove(int v) { root = remove(root, v); }
};

int main() {
  // let's contrast and compare
  BST* T = new BST();                            // an empty BST
  AVL* A = new AVL();                            // an empty AVL

  int n = 12;
  int arr[] = {15, 32, 100, 6, 23, 4, 7, 71, 5, 50, 3, 1};
  for (int i = 0; i < n; i++) {
    T->insert(arr[i]);
    A->insert(arr[i]);
  }

  // Example of C++ polymorphism: method getHeight() returns different value
  printf("%d\n", T->getHeight());                // 4, taller tree
  printf("%d\n", A->getHeight());                // 3, shorter tree

  // Another C++ polymorphism: method inorder() returns similar value
  T->inorder(); // The BST: 1 3 4 5 6 7 15 23 32 50 71 100
  A->inorder(); // The AVL: 1 3 4 5 6 7 15 23 32 50 71 100

  printf("---\n");
  printf("%d\n", A->search(71));                 // found, 71
  printf("%d\n", A->search(7));                  // found, 7
  printf("%d\n", A->search(22));                 // not found, -1

  printf("%d\n", A->findMin());                  // 1
  printf("%d\n", A->findMax());                  // 100

  sort(arr, arr+n);
  printf("---\n");
  for (int i = 0; i < n; i++)
    printf("%d %d %d\n", A->predecessor(arr[i]), arr[i], A->successor(arr[i]));

  // deletion demo
  printf("---\n");
  printf("Current BST/AVL:");
  A->inorder();

  int deletionorder[] = {23, 100, 32, 71, 50, 7, 5, 1, 3, 6, 15, 4};
  for (int i = 0; i < n; ++i) {
    printf("Deleting: %d\n", deletionorder[i]);

    A->remove(deletionorder[i]);
    printf("AVL, height: %d, inorder traversal:", A->getHeight());
    A->inorder();

    T->remove(deletionorder[i]);
    printf("BST, height: %d, inorder traversal:", T->getHeight()); // equal or taller than A->getHeight()
    T->inorder(); // should be the same as A.inorder()
  }
  return 0;
}

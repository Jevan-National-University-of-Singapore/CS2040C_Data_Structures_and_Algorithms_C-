#include <iostream>
#include <stack>

using namespace std;




struct Node {
    Node* left;
    Node* right;
    int val;
    Node (int val) {
        this->val = val;
        left = right = NULL;
    }
};

struct Tree {
    Node* root;
};

void dfs(Tree tr) {
    stack<Node *> stk;
    Node *curr = tr.root;
    while(!stk.empty() || curr) {
        // If curr is NULL, then it enters here to go up the stack
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();

        // first iteration, this is the smallest number
        cout << curr->val << ' ';

        // traverse right
        curr = curr->right;
        
    } 
}

int main() 
{ 
  
    /* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
    struct Tree tree;
    tree.root = root;
  
    dfs(tree); 
    return 0; 
} 
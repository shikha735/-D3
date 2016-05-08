#include <iostream>
#include <climits>
#include <stack>
#include <vector>
using namespace std;

struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
    BstNode(int val): left(NULL), right(NULL), data(val) {};
};

/*
// First approach -- O(n2)

bool isSubtreeLesser(BstNode* root, int val){
    if(root == NULL) return true;
    if((root->data <= val)
       && isSubtreeLesser(root->right,val)
       && isSubtreeLesser(root->left,val))
        return true;
    return false;
}

bool isSubtreeGreater(BstNode* root, int val){
    if(root == NULL) return true;
    if((root->data > val)
       && isSubtreeGreater(root->right,val)
       && isSubtreeGreater(root->left,val))
        return true;
    return false;
}

bool isBST(BstNode* root){
    if(root == NULL) return true;
    if(isSubtreeGreater(root->right,root->data)
       && isSubtreeLesser(root->left,root->data)
       && isBST(root->right, minValue, root->data)
       && isBST(root->left, root->data, maxValue))
        return true;
    return false;
}

*/

// Second approach -- O(n)
bool isBSTUtil(BstNode* root, int minValue, int maxValue){
    if(root == NULL) return true;
    if(root->data > minValue && root->data < maxValue
       && isBSTUtil(root->left, minValue, root->data)
       && isBSTUtil(root->right, root->data, maxValue))
        return true;
    return false;
}

bool isBST(BstNode* root){
    return isBSTUtil(root,INT_MIN, INT_MAX);
}

BstNode* insertNode(BstNode* root, int val){
    if(root == NULL)
        root = new BstNode(val);
    else if(root->data < val)
        root->right = insertNode(root->right,val);
    else
        root->left = insertNode(root->left, val);
    return root;
}

// inorder traversal can be used for checking if the binary tree is BST
void inorder(BstNode* root){
    if(root == NULL) return;
    stack<BstNode*> S;
    vector<int> res;
    while(1){
        if(root != NULL){
            S.push(root);
            root = root->left;
        }
        else{
            if(S.empty()) break;
            root = S.top();
            S.pop();
            res.push_back(root->data);
            root = root->right;
        }
    }
    for(int i=1;i<res.size();i++)
        if(res.at(i-1)>res.at(i)){
            cout << "Not a BST" <<endl;
            return;
        }
    cout << "BST";
}

int main(){
    BstNode* root = NULL;

    root = insertNode(root,5);
    root = insertNode(root,2);
    root = insertNode(root,3);
    root = insertNode(root,9);
    inorder(root);
    if(isBST(root)) cout << "BST"<< endl;
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* createNode(int val){
    BstNode* newnode = new BstNode();
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

BstNode* insertNode(BstNode* root, int val){
    if(root == NULL) { // empty tree
		root = createNode(val);
	}
    // if data to be inserted is lesser, insert in left subtree.
	else if(val <= root->data) {
		root->left = insertNode(root->left,val);
	}
    // else, insert in right subtree.
	else {
		root->right = insertNode(root->right,val);
	}
	return root;
}

bool searchTree(BstNode* root, int val){
    if(root == NULL)
        return false;
    else if(root->data == val)
        return true;
    else if(val <= root->data)
        return searchTree(root->left, val);
    else
        return searchTree(root->right, val);
}

// BFS
void levelOrder(BstNode *root){
	if(root == NULL) return;
	queue<BstNode*> Q;
	Q.push(root);
	while(!Q.empty()){
        BstNode* current = Q.front();
        cout << current->data << '\t';
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
	}
}

// Preorder traversal is used to create a copy of the tree. Time - O(n) Space -O(h)
// Preorder traversal is also used to get prefix expression on of an expression tree.
void recPreorder(BstNode* root){
    if(root!=NULL){
        cout << root->data << '\t';
        recPreorder(root->left);
        recPreorder(root->right);
    }
}

// non recursive, iterative approach using stack
void preorder(BstNode* root){
    if(root == NULL) return;
    stack<BstNode*> S;
    BstNode* current = root;
    S.push(current);
    while(!S.empty()){
        current = S.top();
        S.pop();
        cout << current->data << '\t' ;
        if(current->right != NULL)
            S.push(current->right);
        if(current->left != NULL)
            S.push(current->left);
    }
}

// Inorder traversal gives nodes in non-decreasing order. Time - O(n) Space -O(h)
void recInorder(BstNode* root){
    if(root!=NULL){
        recInorder(root->left);
        cout << root->data << '\t';
        recInorder(root->right);
    }
}

// non recursive, iterative approach using stack
void inorder(BstNode* root){
    if(root == NULL) return;
    stack<BstNode*> S;
    BstNode* current = root;
    while(1){
        if(current!=NULL){
            S.push(current);
            current = current->left;
        }
        else{
            if(S.empty()) break;
            current = S.top();
            S.pop();
            cout << current->data << '\t';
            current = current->right;
        }
    }
}

//Postorder traversal is used to delete the tree. Time - O(n) Space -O(h)
// and to get the postfix expression of an expression tree.
void recPostorder(BstNode* root){
    if(root!=NULL){
        recPostorder(root->left);
        recPostorder(root->right);
        cout << root->data << '\t';
    }
}

// non recursive, iterative approach using stack
void postorder(BstNode* root){
    if(root == NULL) return;
    stack<BstNode*> S1, S2;
    BstNode* current = root;
    S1.push(current);
    while(!S1.empty()){
        current = S1.top();
        S1.pop();
        S2.push(current);
        if(current->left != NULL)
            S1.push(current->left);
        if(current->right != NULL)
            S1.push(current->right);
    }
    while(!S2.empty()){
        current = S2.top();
        S2.pop();
        cout << current->data << '\t';
    }
}

int findHeight(BstNode* root){
    if(root == NULL)
        return -1;
    return max(findHeight(root->left),findHeight(root->right)) + 1;
}

// finding min element
BstNode* findMin(BstNode* root){
    while(root->left != NULL) root = root->left;
    return root;
}

// Deleting a node from BST
BstNode* deleteNode(BstNode* root, int val){
    if(root == NULL) return root;
    else if(val < root->data) root->left = deleteNode(root->left, val);
    else if (val > root->data) root->right = deleteNode(root->right, val);
    else{
        // No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        // one child
        else if(root->left == NULL){
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }
        // two children
        else{
            BstNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;
}

BstNode* Find(BstNode* root,int val){
    if(root == NULL) return NULL;
    else if(val == root->data) return root;
    else if(val < root->data) return Find(root->left, val);
    else return Find(root->right, val);
}

// finding In order successor
BstNode* getSuccessoor(BstNode* root, int data){
    BstNode* current = Find(root, data);
    if(current == NULL) return NULL;

    // if it has right subtree
    if(current->right != NULL){
        return findMin(current->right);
    }
    // if it does not have right subtree
    else{
        BstNode* successor = NULL;
        BstNode* ancestor = root;
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

int main(){
    BstNode* root = NULL;
    int val, option;

    do{
        cout << "\nMenu:" << endl;
        cout << "1. Insert \n2. Search \n3. Preorder Traversal \n4. Inorder Traversal \n5. Postorder Traversal \n6. Height \n7. Level Order \n8. Exit ";
		cout << "\n*** Without recursion *** \n9. Preorder \n10. Inorder \n11. Postorder \n12. Delete \n13. Inorder Successor \nEnter option: " << endl;
        cin >> option;

        switch(option){
            case 1: cout << "Enter the value to insert: ";
                    cin >> val;
                    root = insertNode(root,val);
                    break;

            case 2: cout << "Enter the value to search for: ";
                    cin >> val;
                    if(searchTree(root,val) == true){
                        cout << "Value found";
                    }
                    else
                        cout << "Value not found";
                    break;

            case 3: recPreorder(root);
                    break;

            case 4: recInorder(root);
                    break;

            case 5: recPostorder(root);
                    break;

            case 6: cout << "Height of the BST is: " << findHeight(root);
                    break;

            case 7: levelOrder(root);
                    break;

            case 8: exit(0);

            case 9: preorder(root);
                    break;

            case 10: inorder(root);
                     break;

            case 11: postorder(root);
                     break;

            case 12: cout << "Enter the value to be deleted: ";
                     cin >> val;
                     deleteNode(root, val);
                     break;

            case 13: cout << "Enter the value for which you want to find inorder successor: ";
                     cin >> val;
                     BstNode* successor = getSuccessoor(root, val);
                     if(successor != NULL) cout << successor->data;
                     else cout << "Does not exists";
                     break;
        }
    }while(1);
    return 0;
}

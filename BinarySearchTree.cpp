#include <iostream>
#include <cstdlib>

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

// Preorder traversal is used to create a copy of the tree.
// Preorder traversal is also used to get prefix expression on of an expression tree.
void preorder(BstNode* root){
    if(root!=NULL){
        cout << root->data << '\t';
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal gives nodes in non-decreasing order.
void inorder(BstNode* root){
    if(root!=NULL){
        inorder(root->left);
        cout << root->data << '\t';
        inorder(root->right);
    }
}

//Postorder traversal is used to delete the tree
// and to get the postfix expression of an expression tree.
void postorder(BstNode* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << '\t';
    }
}

int main(){
    BstNode* root = NULL;
    int val, option;

    do{
        cout << "\nMenu:" << endl;
        cout << "1. Insert \n2. Search \n3. Preorder Traversal \n4. Inorder Traversal \n5. Postorder Traversal \n6. Exit \nEnter option: " << endl;
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

            case 3: preorder(root);
                    break;

            case 4: inorder(root);
                    break;

            case 5: postorder(root);
                    break;

            case 6: exit(0);
        }
    }while(1);
    return 0;
}

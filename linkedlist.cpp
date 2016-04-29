#include <iostream>
#include <cstdlib>
using namespace std;

// Node declaration
struct Node{
	int data;
	Node *next;
};
Node *head = new Node();

// inserting at the beginning
void insertBeg(int val){
    Node *newnode = new Node();
    newnode->data = val;
    newnode->next = head;
    head = newnode;
    return;
}

// inserting at the end
void insertEnd(int val){
    Node *newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;

    Node *temp = new Node();
    temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return;
}

// insert at nth position
void insertNth(int val, int position){
    Node *newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    if(position == 1){
        newnode->next = head;
        head = newnode;
        return;
    }
    Node *temp = new Node();
    temp = head;
    for(int i=1; i<position-1;i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

// delete from beginning
void deleteBeg(){
    Node *temp = new Node();
    temp = head;
    head = head->next;
    delete temp; //free(temp);
    return;
}


// delete from the end
void deleteEnd(){
    Node *pres = new Node();
    Node *prev = new Node();
    pres = head;
    while(pres->next!=NULL){
        prev = pres;
        pres = pres->next;
    }
    prev->next= pres->next;
    delete pres; //free(pres);
    return;
}


// delete from nth position
void deleteNth(int position){
    Node *temp = new Node();
    temp = head;
    if(position == 1){
        head = head->next;
        delete temp;
        return;
    }
    for(int i=1;i<position-1;i++){
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;//free(temp2);
    return;
}

// To display the elements in linked list
void display(){
    Node *temp = new Node();
    temp = head;
    while(temp!=NULL){
        cout << temp->data<< '\t';
        temp = temp->next;
    }
    return;
}

// display linked list in reverse order
void displayReverse(Node* head){
    Node *temp = head;
    if(temp!=NULL){
        displayReverse(temp->next);
        cout << temp->data << '\t';
    }
    return;
}

// reversing a linked list iteratively
void reverseIterative(){
	Node *curr, *prev, *currnext;
	prev = NULL;
	curr = head;
	while(curr!=NULL){
        currnext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = currnext;
	}
	head = prev;
}

// reversing a linked list using recursion
void reverseRecursive(Node *temp){
    if(temp->next == NULL){
        head = temp;
        return;
    }
    reverseRecursive(temp->next);
    // Node *prev = temp->next;
    // prev->next = temp;
    // temp->next = NULL;
    temp->next->next = temp;
    temp->next = NULL;
}

// main function
int main(){

    head = NULL;
    int option, val, position;

    do{
        cout << "\nMenu:" << endl;
        cout << "\n1. InsertBegin \n2. InsertEnd \n3. Insert at nth position \n4. DeleteBegin \n5. DeleteEnd \n6. Delete from nth position \n7. Display \n8. Exit";
        cout << " \n9. Reverse Iterative \n10. Reverse Recursive \n11. Display in reverse order \nEnter option: ";
        cin >> option;
        switch(option){
        case 1: cout << "Enter the value to insert: ";
                cin >> val;
                insertBeg(val);
                break;

        case 2: cout << "Enter the value to insert: ";
                cin >> val;
                insertEnd(val);
                break;

        case 3: cout << "Enter the position to insert: ";
                cin >> position;
                cout << "\n Enter the value to insert: ";
                cin >> val;
                insertNth(val, position);
                break;

        case 4: if(head == NULL){
                    cout << "Linked List empty!!";
                    break;
                }
                deleteBeg();
                break;

        case 5: if(head == NULL){
                    cout << "Linked List empty!!";
                    break;
                }
                deleteEnd();
                break;

        case 6: if(head == NULL){
                    cout << "Linked List empty!!";
                    break;
                }
                cout << "Enter the position of node to delete: ";
                cin >> val;
                deleteNth(val);
                break;

        case 7: if(head == NULL){
                    cout << "Linked List empty!!";
                    break;
                }
                cout << "Elements in the linked list are: " << endl;
                display();
                break;

        case 8: exit(0);

        case 9: reverseIterative();
                break;

        case 10: reverseRecursive(head);
                 break;

        case 11: displayReverse(head);
                 break;

        default: cout << "Enter valid option" << endl;
        }
    }while(1);

    return 0;
}

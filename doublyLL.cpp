#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *head;

Node* createNode(int val){
    Node *newnode = new Node();
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = head;
    return newnode;
}

void insertBeg(int val){
    Node *newnode = createNode(val);
    if(head == NULL){
        head = newnode;
        return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertEnd(int val){
     Node *temp = head;
     Node *newnode = createNode(val);
     if(head == NULL){
        head = newnode;
        return;
     }

     while(temp->next!=NULL){
        temp = temp->next;
     }
     temp->next = newnode;
     newnode->prev = temp;
     newnode->next = NULL;
}

void deleteBeg(){
    Node *temp = new Node();
    temp = head;
    head = head->next;
    head ->prev = NULL;
    delete temp; //free(temp);
    return;
}

void deleteEnd(){
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node *tempprev = temp->prev;
    tempprev->next = NULL;
    delete temp;
}

void display(){
    Node *temp;
    temp = head;
    while(temp!=NULL){
        cout << temp->data << '\t';
        temp = temp->next;
    }
}

void displayReverse(){
    Node *temp;
    temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    while(temp!=NULL){
        cout << temp->data << '\t';
        temp = temp->prev;
    }
}

int main(){
    head = NULL;
    int option, val, position;

    do{
        cout << "\nMenu:" << endl;
        cout << "\n1. InsertBegin \n2. InsertEnd \n3. DeleteBegin \n4. DeleteEnd \n5. Display \n6. Display in reverse order \n7. Exit";
        cout << " \nEnter option: ";
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

        case 3: if(head == NULL){
                    cout << "Linked List empty!!";
                    break;
                }
                deleteBeg();
                break;

        case 4: if(head == NULL){
                    cout << "Linked List empty!!";
                    break;
                }
                deleteEnd();
                break;

        case 5: if(head == NULL){
                    cout << "Linked List empty!!";
                    break;
                }
                cout << "Elements in the linked list are: " << endl;
                display();
                break;

        case 6: if(head == NULL){
                    cout << "Linked List empty!!";
                    break;
                }
                cout << "Elements in the linked list are: " << endl;
                displayReverse();
                break;


        case 7: exit(0);

        default: cout << "Enter valid option" << endl;
        }
    }while(1);

    return 0;
}

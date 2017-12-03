#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class List{
public:
        Node* firstNode = NULL;
        void init(int n,Node* node = NULL);
        void get(int index);
        void addByIndex(int n, int index);
        void removeFromIndex(int index);
        void print(Node* n);
};

void List::init(int n, Node* node){
        if(firstNode == NULL){
        firstNode = new Node(n);
        return;
        }
        if(node->next != NULL){
            init(n, node->next);
            return;
        }
        Node* newNode = new Node(n);
        node->next = newNode;
    }


void List::get(int index){
        Node* n = firstNode;
        for(int i = 0; n != NULL;i++){
            n = n->next;
            if(i == index - 1){
                cout<<"Element with index - "<<index<< " -> " <<n->data<<endl;
                return;
            }
        }
    }

void List::addByIndex(int n,int index){
    Node* temp = firstNode;
    int count = 0;
    while(temp != NULL){
          if(count == index - 1){
            Node* it = new Node(n);
            it->next = temp->next;
            it->prev = temp;
            temp->next = it;
            it->next->prev = it;
            break;
        } else {
            count++;
            temp = temp->next;
        }
    }
 }

 void List::removeFromIndex(int index){
    Node* temp1 = firstNode;
    for(int i = 1; i <= index - 1;i++){
       temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
    }

void List::print(Node* n){
    cout<<n->data<<" ";
    while(n->next != NULL){
       print(n->next);
       return;
    }
}

int main(){
    List l;

    l.init(12,l.firstNode);
    l.init(23,l.firstNode);
    l.init(27,l.firstNode);
    l.init(56,l.firstNode);
    l.init(78,l.firstNode);

    cout<<"List : "<<endl;
    l.print(l.firstNode);
    cout<<"\n\nGET : "<<endl;
    l.get(3);
    cout<<"\nAdd 125 by index ** 4 ************\n"<<endl;
    l.addByIndex(125,4);
    l.print(l.firstNode);
    cout<<endl;
    cout<<"\nRemove 27 from index ** 2 ************\n"<<endl;
    l.removeFromIndex(2);
    l.print(l.firstNode);
    cout<<endl;
}

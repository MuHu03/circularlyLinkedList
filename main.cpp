#include <iostream>
using namespace std;

class node{
    friend class linklist;
private:
    int info;
    node *next;
};
class linklist{
private:
    node *first;
public:
    linklist(){
        first=NULL;
    }
    int empty(){
        if (first==NULL){
            return 1;
        } else{
            return 0;
        }
    }
    node* createNode(int x){
        node *newNode=new node;
        if (newNode==NULL){
            cout<<"there is a problem in creating node "<<endl;
        }
        newNode->info=x;
        newNode->next=NULL;
        return newNode;
    }
    void insert(int x) {
        node* newNode = createNode(x);
        if (empty()) {
            newNode->next = newNode;
        } else {
            newNode->next = first->next;
            first->next = newNode;
        }
        first = newNode;
    }
    void addToBeginning(int x){
        node *temp = createNode(x);
        temp->next=first->next;
        first->next=temp;
    }
    node* search(int x){
        //If you need to access a specific node, you can use this function
        if (empty()){
            cout<<"link list is empty"<<endl;
        } else {
            node *temp=first;
            do{
                temp=temp->next;
            }while (temp != NULL && temp->info!=x);
                if (temp==NULL){
                    cout<<"The desired node was not found"<<endl;
                }else{
                    return temp;
                }
        }
    }
    void deletNode(){
        if (empty()){
            cout<<"your link list is empty";
        } else {
            node *temp=first;
            node *deletedNode;
            do {
                temp=temp->next;
            } while (temp->next!=first);
            deletedNode=temp->next;
            temp->next=first->next;
            first=temp;
            delete deletedNode;
        }
    }
    void merging(linklist subli){
        node *temp1=first;
        node *temp2=subli.first;
        node *temp=temp2->next;
        temp2->next=temp1->next;
        temp1->next=temp;
    }
    void print() {
        node* temp = first->next;
        int i=1;
        if (empty()){
            cout<<"the list is empty "<<endl;
        } else{
            do {
                cout<<i<<" th node is : "<<temp->info<<endl;
                temp = temp->next;
                i++;
            } while (temp != first->next);
        }
    }
    ~linklist(){};
};

int main() {
    linklist li1,li2;
    for (int i = 1; i <=5 ; ++i)
        li1.insert(i);
    cout<<"this the first list : "<<endl;
    li1.print();
    cout<<"============================"<<endl;
    li1.deletNode();
    li1.print();
    cout<<"============================"<<endl;
    cout<<"add a node to beginning"<<endl;
    li1.addToBeginning(125);
    li1.print();
    cout<<"============================"<<endl;
    for (int j = 10; j <=50 ; j=j+10)
        li2.insert(j);
    cout<<"this is the second list : "<<endl;
    li2.print();
    cout<<"============================"<<endl;
    li2.merging(li1);
    cout<<"Add To End : "<<endl;
    li1.print();
    return 0;
}

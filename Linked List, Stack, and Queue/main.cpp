#include <iostream>
using namespace std;
template<typename t>
class node{

public:
    t data;
    node*next;
    node*prev;
    node(){
        next= nullptr;
        prev= nullptr;
    }
    node(t val){
        data=val;
        next= nullptr;
        prev= nullptr;
    }
};
template<typename t>
class linkedlist{
    node<t>*head;
public:
    linkedlist(){
        head== nullptr;
    }
    bool isempty(){
        return head== nullptr;
    }
    bool isfound(t val){
        node<t>*temp=head;
        bool f=0;
        while(temp!= nullptr){
            if(temp->data==val){
                f=1;
                break;
            }
            temp=temp->next;
        }
       return f;
    }
    void insertfirst(t val){
        if(isempty()){
            node<t>*newnode=new node<t>(val);
            head=newnode;
        }
        else{
            node<t>*newnode=new node<t>(val);
            newnode->next=head;
            head=newnode;
        }
    }
    void insertlast(t val){
        node<t>*temp=head;
        node<t>*newnode=new node<t>(val);
        while(temp->next!= nullptr){
            temp=temp->next;
        }
        temp->next=newnode;

    }
    void insertbefore( t val, t item){
        if(isfound(val)){
            if(head->data==val){
                insertfirst(item);
                return;
            }
            node<t>*temp=head;
            node<t>*prev= nullptr;
            while(temp->data!=val){
                prev=temp;
                temp=temp->next;
            }
            node<t>*newnode=new node<t>(item);
            prev->next=newnode;
            newnode->next=temp;

        }
        else{
            cout<<"the item is not founddd\n";
        }
    }
    void insert(int idx, t val){
        int index=-1;
        if(idx>count()|| idx<0)
            cout<<"out of range!!\n";
        else{
            if(idx==0){
                insertfirst(val);
            }
            else if(idx==count()){
                insertlast(val);

            }
            else{
                node<t>*prev=head;
                while(index!=idx-2){
                    index++;
                    prev=prev->next;
                }
                node<t>*newnode=new node<t>(val);
                newnode->next=prev->next;
                prev->next=newnode;
            }

        }
    }
    int count(){
        node<t>*temp=head;
        int cnt=0;
        while(temp!= nullptr){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    void display(){
        node<t>*temp=head;
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void deletefirst(){
        if(isempty()){
            cout<<"list is empty\n";
        }
        else{
            node<t>*temp=head;
            head=head->next;
            delete temp;
        }
    }
    void deletelast(){
        if(isempty()){
            cout<<"list is empty\n";
        }
        else{
            node<t>*temp=head,*prev= nullptr;
            while(temp->next!= nullptr){
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            delete temp;
        }
    }
    void delette(t val){
        if(isempty()){
            cout<<"list is empty\n";
        }
        else if(!isfound(val)){
            cout<<"the item is not foundd!!\n";
        }
        else if(head->data==val){
            deletefirst();
        }
        else{
            node<t>*temp=head,*prev= nullptr;
            while( temp->data!=val){
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            delete temp;
        }
    }
    int search(int val){
        int f=0;
        if(!isfound(val))
            return -1;
        node<t>*temp=head;
        while(temp->data!=val){
            f++;
            temp=temp->next;
        }
        return f;
    }
};
template<typename t>
class doublylinkedlist{
node<t>*head;
node<t>*last;
public:
    doublylinkedlist(){
        head= nullptr;
        last= nullptr;
    }
    bool isempty(){
        return head== nullptr&&last== nullptr;
    }
    bool isfound(t val){
        node<t>*temp=head;
        bool f=0;
        while(temp!= nullptr){
            if(temp->data==val){
                f=1;
                break;
            }
            temp=temp->next;
        }
        return f;
    }
    void insertfirst(t val){
        if(isempty()){
            node<t>*newnode=new node<t>(val);
            head=newnode;
            last=newnode;
        }
        else{
            node<t>*newnode=new node<t>(val);
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }
    void insertlast(t val){
        node<t>*temp=head;
        node<t>*newnode=new node<t>(val);
        while(temp->next!= nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        last=newnode;

    }
    void insertbefore( t val, t item){
        if(isfound(val)){
            if(head->data==val){
                insertfirst(item);
                return;
            }
            node<t>*temp=head;
            node<t>*prv= nullptr;
            while(temp->data!=val){
                prv=temp;
                temp=temp->next;
            }
            node<t>*newnode=new node<t>(item);
            prv->next=newnode;
            newnode->next=temp;
            temp->prev=newnode;
            newnode->prev=prv;
        }
        else{
            cout<<"the item is not founddd\n";
        }
    }
    void insert(int idx, t val){
        int index=-1;
        if(idx>count()|| idx<0)
            cout<<"out of range!!\n";
        else{
            if(idx==0){
                insertfirst(val);
            }
            else if(idx==count()){
                insertlast(val);

            }
            else{
                node<t>*prev=head;
                while(index!=idx-2){
                    index++;
                    prev=prev->next;
                }
                node<t>*newnode=new node<t>(val);
                newnode->next=prev->next;
                prev->next=newnode;
            }

        }
    }
    int count(){
        node<t>*temp=head;
        int cnt=0;
        while(temp!= nullptr){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    void display(){
        node<t>*temp=head;
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void displaydcs(){
        node<t>*temp=last;
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }
    int search(int val){
        int f=0;
        if(!isfound(val))
            return -1;
        node<t>*temp=head;
        while(temp->data!=val){
            f++;
            temp=temp->next;
        }
        return f;
    }
    void deletefirst(){
        if(isempty()){
            cout<<"list is empty\n";
        }
        else{
            node<t>*temp=head;
            head=head->next;
            head->prev= nullptr;
            delete temp;
        }
    }
    void deletelast(){
        if(isempty()){
            cout<<"list is empty\n";
        }
        else{
            node<t>*temp=head,*prev= nullptr;
            while(temp->next!= nullptr){
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            last=temp->prev;
            delete temp;
        }
    }
    void delette(t val){
        if(isempty()){
            cout<<"list is empty\n";
        }
        else if(!isfound(val)){
            cout<<"the item is not foundd!!\n";
        }
        else if(head->data==val){
            deletefirst();
        }
        else{
            node<t>*temp=head,*prev= nullptr;
            while( temp->data!=val){
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            temp->next->prev=prev;
            if(temp->next== nullptr)
                last=temp->prev;
            delete temp;
        }
    }
};
template<typename t>
class stack{
    node<t>*head;
    node<t>*top;
    void insertfirst(t val){
        node<t>*newnode=new node<t>(val);
        head=newnode;
    }

public:
    stack(){
        head=nullptr;
        top= nullptr;
    }
    bool isempty(){
        return head== nullptr;
    }
    bool isfound(t val){
        node<t>*temp=head;
        bool f=0;
        while(temp!= nullptr){
            if(temp->data==val){
                f=1;
                break;
            }
            temp=temp->next;
        }
        return f;
    }

    void add(t val){
        if(isempty()){
            insertfirst(val);
            return;
        }

        node<t>*temp=head;
        node<t>*newnode=new node<t>(val);
        while(temp->next!= nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
        top=newnode;
    }

    int count(){
        node<t>*temp=head;
        int cnt=0;
        while(temp!= nullptr){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    void display(){
        node<t>*temp=head;
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void remove(){
        if(isempty()){
            cout<<"list is empty\n";
        }
        else{
            node<t>*temp=head,*prev= nullptr;
            while(temp->next!= nullptr){
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            top=prev;
            delete temp;
        }
    }

    int search(int val){
        int f=0;
        if(!isfound(val))
            return -1;
        node<t>*temp=head;
        while(temp->data!=val){
            f++;
            temp=temp->next;
        }
        return f;
    }
    t gettop(){
        if(top== nullptr)
            return -1;
        else
            return top->data;
    }
};
template<typename t>
class queue{
    node<t>*head;
    void insertfirst(t val){
        node<t>*newnode=new node<t>(val);
        head=newnode;
    }
public:
    queue(){
        head=nullptr;
    }
    bool isempty(){
        return head== nullptr;
    }
    bool isfound(t val){
        node<t>*temp=head;
        bool f=0;
        while(temp!= nullptr){
            if(temp->data==val){
                f=1;
                break;
            }
            temp=temp->next;
        }
        return f;
    }

    void add(t val){
        if(isempty()){
            insertfirst(val);
            return;
        }
        node<t>*temp=head;
        node<t>*newnode=new node<t>(val);
        while(temp->next!= nullptr){
            temp=temp->next;
        }
        temp->next=newnode;

    }

    int count(){
        node<t>*temp=head;
        int cnt=0;
        while(temp!= nullptr){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    void display(){
        node<t>*temp=head;
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void remove(){
        if(isempty()){
            cout<<"list is empty\n";
        }
        else{
            node<t>*temp=head;
            head=head->next;
            delete temp;
        }
    }

    int search(int val){
        int f=0;
        if(!isfound(val))
            return -1;
        node<t>*temp=head;
        while(temp->data!=val){
            f++;
            temp=temp->next;
        }
        return f;
    }
    t getfront(){
        return head->data;
    }

};
template<typename t>
class priorityqueue{
    node<t>*head;
public:
    priorityqueue(){
        head= nullptr;
    }
    bool isempty(){
        return head== nullptr;
    }
    void add(t val){
        if(isempty()){
            head=new node(val);
            return;
        }
        else{
            node<t>* newnode=new node(val);
            node<t>*temp=head, *prv= nullptr;
            if(val<head->data){
                newnode->next=head;
                head=newnode;
                return;
            }
            while(temp!= nullptr&&val>=temp->data){
                prv=temp;
                temp=temp->next;
            }

            newnode->next=temp;
            prv->next=newnode;
        }
    }
    void display(){
        node<t>*temp=head;
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main() {
    priorityqueue <int>l;
    l.add(20);
    l.add(50);
    l.add(10);
    l.add(40);
    l.add(30);
    l.add(15);
    l.display();


}

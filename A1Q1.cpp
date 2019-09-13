/* based off singlelylinkedlist.cpp, added push and pop methods */
/* after adding push and pop methods, I added a queue of queues, where queues are added using push and pop */
/* this is my answer to A1Q1 (A and B) */
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class PatSSList{
    public:
    PatSSList(): head{new PatSSList<T>::PMnode}, tail{head}, length{0}{
        tail->next = nullptr;        
    }
    PatSSList(T a){
        //allocate memory?
        PMnode* p = new PatSSList<T>::PMnode{a};
        head = p;
        tail = p;
        head->next = nullptr;
        length = 1;
    }
    void add(T a){ // can add one node at a time
        PMnode* p = new PatSSList<T>::PMnode{a};
        tail->next = p;
        tail = p;
        length++;
    }
    void add(PatSSList<T> a){ // can several nodes at a time
    // memory should already be allocated and we force reference usage
    // i feel like the memory allocation is fucked up
    PMnode* p1 = a.head;
    while(p1){
        PatSSList<T>::add(p1->data);
        p1 = p1->next;
    } 
    }

    void push(T a){
        // same as add (T a) function except add to to front rather than back
        PMnode* p = new PatSSList<T>::PMnode{a};
        p->next = head;
        head = p;
        length++;
    }

    T pop(){
        // delete memory :/
        PMnode* p = head;
        T q = p->data;
        delete p;
        head=head->next;
        length--;
        return q;
    }
 
    class PMnode{
        public:
        PMnode(T d): data{d}, next{nullptr}{}
        T data;
        PMnode* next;
    };

    T data;
    void print(){
        // assert(length>0);
        PMnode* p = head; 
        while(p){
            cout << p->data << endl;
            p=p->next;
        }
        cout << "length: " << length << endl;
    }
    PMnode* head;
    PMnode* tail;
    int length;    
};

int main(){

    PatSSList<int> madeone{9};
    madeone.add(1312);
    madeone.add(1442);
    madeone.add(12);
    madeone.add(112);
    madeone.print();
    PatSSList<int> m{3};
    m.add(madeone);
    m.print();
    m.add(madeone);
    m.print();
    m.push(155);
    m.push(442);
    m.print();
    m.pop();
    m.pop();
    m.print();
    cout << "tail: " << m.tail->data << endl;
    cout << "head: " << m.head->data << endl;
    // char get_c;
    // cin >> get_c;
}
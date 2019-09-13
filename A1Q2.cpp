/* based off A1Q1.cpp, added doublely linked list*/
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class PatDLList{
    public:
    PatDLList(): head{new PatDLList<T>::PMnode}, tail{head}, length{0}{
        tail->next = nullptr;
        tail->prev = nullptr;        
    }
    PatDLList(T a){
        //allocate memory?
        PMnode* p = new PatDLList<T>::PMnode{a};
        head = p;
        tail = p;
        head->prev = nullptr;
        head->next = nullptr;
        length = 1;
    }
    void add(T a){ // can add one node at a time
        PMnode* p = new PatDLList<T>::PMnode{a};
        tail->next = p;
        tail->next->prev = tail;
        tail = p;
        length++;
    }
    void add(PatDLList<T> a){ // can several nodes at a time
    // memory should already be allocated and we force reference usage
    // i feel like the memory allocation is fucked up
    PMnode* p1 = a.head;
    while(p1){
        PatDLList<T>::add(p1->data);
        p1 = p1->next;
    } 
    }

    void push(T a){
        // same as add (T a) function except add to to front rather than back
        PMnode* p = new PatDLList<T>::PMnode{a};
        p->next = head;
        head->prev = p;
        head = p;
        length++;
    }

    T pop(){
        // delete memory :/
        PMnode* p = head;
        T q = p->data;
        delete p;
        head=head->next;
        head->prev = nullptr;
        length--;
        return q;
    }
 
    class PMnode{ 
        // this node had prev pointer which makes it a doublely linked list
        public:
        PMnode(T d): data{d}, next{nullptr}, prev{nullptr}{}
        T data;
        PMnode* next;
        PMnode* prev; 
    };

    T data;
    void print_backwards(){
        // assert(length>0);
        cout << "backwards: " << endl;
        PMnode* p = tail; 
        while(p){
            cout << p->data << endl;
            p=p->prev;
        }
        cout << "length: " << length << endl;
    }

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

    PatDLList<int> madeone{9};
    madeone.add(1312);
    madeone.add(1442);
    madeone.add(12);
    madeone.add(112);
    madeone.print();
    PatDLList<int> m{3};
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
    m.print_backwards();
    cout << "tail: " << m.tail->data << endl;
    cout << "head: " << m.head->data << endl;
    // char get_c;
    // cin >> get_c;
}
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class PatSList{
    public:
    PatSList(): head{new PatSList<T>::PMnode}, tail{head}, length{0}{
        tail->next = nullptr;        
    }
    PatSList(T a){
        //allocate memory?
        PMnode* p = new PatSList<T>::PMnode{a};
        head = p;
        tail = p;
        head->next = nullptr;
        length = 1;
    }
    void add(T a){ // can add one node at a time
        PMnode* p = new PatSList<T>::PMnode{a};
        tail->next = p;
        tail = p;
        length++;
    }
    void add(PatSList<T> a){ // can several nodes at a time
    // memory should already be allocated and we force reference usage
    // i feel like the memory allocation is fucked up
    PMnode* p1 = a.head;
    while(p1){
        PatSList<T>::add(p1->data);
        p1 = p1->next;
    } 
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

    PatSList<int> madeone{9};
    madeone.add(1312);
    madeone.add(1442);
    madeone.add(12);
    madeone.add(112);
    madeone.print();
    PatSList<int> m{3};
    m.add(madeone);
    m.print();
    m.add(madeone);
    m.print();
    cout << "tail: " << m.tail->data << endl;
    cout << "head: " << m.head->data << endl;
    // char get_c;
    // cin >> get_c;
}
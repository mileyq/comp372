#include <iostream>
using namespace std;

template <typename T>
class queue_array{
    public:
    queue_array(const int msize, T* marray):n{msize}, size{msize*2}{
        // size of array (n) must be greater or equal array
        // class will self manage array size by allocating additional
        // the allocated size is 2*the required size
        narray = new T[size]; 
        for(int i = 0; i<n; i++) narray[i] = *(marray+i);
    }
    void print_all(){
        for (int i = 0; i<n; i++) cout << narray[i] << endl;
    }

    T* narray;
    int size; // array max
    int n ; //elements filled 
};

int main(){
    const int k = 5;
    int a[k]={5,5,3,2,1};
    queue_array<int> b(k, &a[0]);
    b.print_all();
}
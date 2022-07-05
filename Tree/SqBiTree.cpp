#include <iostream>
#include <vector>

template <class T>
class SqBiTree{
    std::vector<T> data;
public:
    SqBiTree(int size = 0){
        if(size) data.resize(size);
    }
    T& operator[](int i) {return data[i];}
    T operator[](int i) const {return data[i];}
    int left_child(int i) const {return 2*i+1;}
    int right_child(int i) {return 2*i+2;}
    int parent(int i) const {return (i+1)/2 - 1;}
    int find(T e) const {

        return 0;
    }
};

int main(){
    SqBiTree<char> t(10);
    t[1] = 'A';
    t[2] = 'B'; 
    return 0;
}
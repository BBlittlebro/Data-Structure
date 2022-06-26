#include <iostream>

template <class T>
class Stack{
    T *data;
    T *top;
    int capacity;
public:
    Stack(int cap = 5){
        data = new T[cap];
        if(!data){throw "記憶體分配錯誤！\n";}
        top = data;
        capacity =cap;
    }
    bool push(T e){
        if(top - data >= capacity){
            T *p = new T[capacity*2];
            if(!p){throw "記憶體分配錯誤！\n"; return false;}
            for(int i = 0; i < capacity; ++i){
                p[i] = data[i];
            }
            delete[] data;
            data = p;
            top = p+capacity;
            capacity *= 2;
        }
        *top = e;
        top += 1;
        return true;
    }
    T& top_is(){
        if(top == data) {throw "It's empty.\n";}
        return *(top-1);
    }
    bool pop(){
        if(top == data) {throw "It's empty.\n"; return false;}
        top -= 1;
        return true;
    }
    bool empty(){
        return top == data;
    }
    void clear(){
        top = data;
    }
};

using std::string;

int main(){
    Stack <char> s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    while(!s.empty()){
        char temp = s.top_is(); std::cout << temp << " ";
        s.pop();
    }
    std::cout << std::endl;

    Stack <string> name;
    name.push("Andy");
    name.push("Beef");
    name.push("Candy");
    name.push("Dog");
    while(!name.empty()){
        string temp = name.top_is(); std::cout << temp << " ";
        name.pop();
    }
    std::cout << std::endl;
}

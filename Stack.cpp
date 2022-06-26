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
bool is_left(char ch){
    return (ch == '(' || ch == '[' || ch == '{');
}
bool is_right(char ch){
    return (ch == ')' || ch == ']' || ch == '}');
}
bool is_matched(const char c1, const char c2){
    if(c1 == '(' && c2 == ')')
        return true;
    if(c1 == '[' && c2 == ']')
        return true;
    if(c1 == '{' && c2 == '}')
        return true;
    return false;
}

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

    /*  進制轉換  */
    int num, d = 2;
    std::cin >> num;
    Stack <int> converse;

    while(num){
        converse.push(num%d); num /= d;
    }
    while(!converse.empty()){
        int temp = converse.top_is(); std::cout << temp << " ";
        converse.pop();
    }
    std::cout << std::endl;

    /* 括號配對 */

    string s_in;
    Stack <char> pair;
    std::cin >> s_in;
    for(int i = 0; i < s_in.size(); ++i){
        if(is_left(s_in[i])){
            pair.push(s_in[i]);
        }else if(is_right(s_in[i])){
            if(pair.empty()){
                throw "It is empty!\n";
                return 0;
            }
            char temp = pair.top_is();
            if(!is_matched(temp, s_in[i])){
                printf("Not matched!\n");
                return 0;
            }
            pair.pop();
        }else{}
    }
    if(pair.empty())
        printf("It is a legal expression.\n");
    else
        printf("It is not a legal expression.\n");
}

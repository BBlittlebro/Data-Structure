#include <iostream>
#include "Stack.h"

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

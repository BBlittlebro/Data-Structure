#include "Stack.h"

int main(){
    int num, d;
    printf("Please enter a num: ");
    std::cin >> num;
    printf("Please enter a digit you want to change: ");
    std::cin >> d;
    Stack <int> converse;

    while(num){
        converse.push(num%d); num /= d;
    }
    while(!converse.empty()){
        int temp = converse.top_is(); std::cout << temp << " ";
        converse.pop();
    }
    std::cout << std::endl;
}
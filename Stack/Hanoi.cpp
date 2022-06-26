#include <iostream>

void move(char num, char start, char goal){
    printf("Move %d from %c to %c.\n", num, start, goal);
}

void hanoi(int n, char start, char temp, char goal){
    if(n == 1) move(1, start, goal);
    else{
        hanoi(n-1, start, goal, temp);
        move(n, start, goal);
        hanoi(n-1, temp, start, goal);
    }
}

int main(){
    int num = 0;
    printf("Please enter a integer: \n");
    std::cin >> num;


    hanoi(num, 'A', 'B', 'C');
}
#include "Stack.h"
using std::string;

char op_table[][7] = {
    {'>','>','<','<','<','>','>'},
    {'>','>','<','<','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'<','<','<','<','<','=','!'},
    {'>','>','>','>','!','>','>'},
    {'<','<','<','<','<','!','='},
};
int index_of_op(const char op){
    if(op == '+') return 0;
    else if(op == '-') return 1;
    else if(op == '*') return 2;
    else if(op == '/') return 3;
    else if(op == '(') return 4;
    else if(op == ')') return 5;
    else return 6;      // '#'
}
int prior(const char op1, const char op2){
    int i = index_of_op(op1);
    int j = index_of_op(op2);
    char cmp = op_table[i][j];

    if(cmp == '>') return 1;
    else if(cmp == '<') return -1;
    else if(cmp == '=') return 0;
    return 9999;  //不可能
}
// n1 op n2 (做計算)
int calculate(int n1, int n2, char op){
    if(op == '+') return (n1 + n2);
    else if(op == '-') return (n1 - n2);
    else if(op == '*') return (n1 * n2);
    else if(op == '/') return (n1 / n2);
    return 0;
}

int main(){
    Stack <int> num;
    Stack <char> mark;
    string exp = "3+2*4/(4-2)#";
    mark.push('#');

    for(int i = 0; i < exp.size();){
        if(exp[i] >= '0' && exp[i] <= '9'){
            num.push(exp[i] - '0');
            ++i;
        }
        else{
            char op1 = mark.top_is();
            int cmp = prior(op1, exp[i]);
            if(cmp == 9999){
                printf("Your question is wrong!\n");
                return 0;
            }
                
            if(cmp < 0){
                mark.push(exp[i]);
                ++i;
            }else if(cmp > 0){
                mark.pop();
                int n1 = num.top_is(); num.pop();
                int n2 = num.top_is(); num.pop();
                int temp = calculate(n2, n1, op1);
                num.push(temp);
            }else if(cmp == 0){
                mark.pop();
                ++i;
            }
        }
    }
    std::cout << num.top_is() << std::endl;
}
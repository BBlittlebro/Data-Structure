#include "Stack.h"
using std::string;
/* 括號配對 */

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

int main(){
    string s_in;
    Stack <char> pair;
    std::cin >> s_in;
    for(int i = 0; i < s_in.size(); ++i){
        if(is_left(s_in[i])){
            pair.push(s_in[i]);
        }else if(is_right(s_in[i])){
            if(pair.empty()){
                printf("Not legal.\n");
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
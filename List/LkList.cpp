#include <iostream>

template <class T>
class LkList{
    struct Node{
        T data;
        Node *next;
    };
    Node *head;
public:
    LkList(){ 
        head = new Node();
        if(!head) throw "LkList 分佈記憶體錯誤!";
        head->next = 0;
    }
    bool get(int i, T &e){
        if(i <= 0) return false;
        Node *p = head; int j = 0;
        while(p && j < i){      //找 i 號節點
            p = p->next;
            ++j;
        }
        if(!p) return false;
        e = p->data;
        return true;
    }
    bool set(int i, T e){
        if(i <= 0) return false;
        Node *p = head; int j = 0;
        while(p && j < i){      //找 i 號節點
            p = p->next;
            ++j;
        }
        if(!p) return false;
        p->data = e;
        return true;
    }
    bool insert(int i, T e){
        if(i <= 0) return false;
        Node *p = head;
        int j = 0;
        while(p && j < i-1){    //找 i-1 號節點
            p = p->next;
            ++j;
        }
        if(!p) return false;
        Node *s = new Node();
        if(!s) return false;
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
    bool remove(int i){
        Node *p = head;
        int j = 0;
        while(p && j < i-1){    //找 i-1 號節點
            p = p->next;
            ++j;
        }
        if(!p) return false;
        Node *q = p->next;
        p->next = q->next;
        delete q;
        return true;
    }
    bool insert_front(T e){
        Node *p = new Node();
        if(!p) return false;
        p->data = e;
        p->next = head->next;
        head->next = p;
        return true;
    }
    bool remove_front(T e){
        Node *p = head->next;
        head->next = p->next;
        delete p;
        return true;
    }
    bool push_back(T e){
        Node *p = head;
        while(p->next){
            p = p->next;
        }
        Node *q = new Node();
        p->next = q;
        q->data = e;
        q->next = 0;
        return true;
    }
    void traverse(void (*fp)(T &e)){
        Node *p = head->next;
        while(p){    
            fp(p->data);
            p = p->next;
        }
    }
    int size(){
        Node *p = head->next;
        int j = 0;
        while(p){    
            p = p->next;
            ++j;
        }
        return j;
    }
    void converse(){
        Node *p = head->next;
        head->next = 0;
        while(p){
            Node *q = p->next;
            p->next = head->next;
            head->next = p;
            p = q;
        }
    }
    T operator[](int i) const{
        if(i < 0) throw "Not find";
        Node *p = head; int j = -1;
        while(p && j < i){      //找 i 號節點
            p = p->next;
            ++j;
        }
        if(!p) throw "Not find";
        return p->data;
    }
    T& operator[](int i){
        if(i < 0) throw "Not find";
        Node *p = head; int j = -1;
        while(p && j < i){      //找 i 號節點
            p = p->next;
            ++j;
        }
        if(!p) throw "Not find";
        return p->data;
    }
};

template <typename T>
void Print(T &temp){
    std::cout << temp << " ";
}

#include <string>
using std::string;

int main(){
    LkList <char> L;
    L.push_back('A'); L.traverse(Print); std::cout << std::endl;
    L.push_back('B'); L.traverse(Print); std::cout << std::endl;
    L.insert_front('C'); L.traverse(Print); std::cout << std::endl;
    L.insert(2, 'E'); L.traverse(Print); std::cout << std::endl;
    L.set(1, 'D'); L.traverse(Print); std::cout << std::endl;

    LkList <string> List2;
    List2.push_back("Andy");
    List2.push_back("Banana");
    List2.push_back("Candy");
    List2.push_back("Dog");
    List2.traverse(Print); std::cout << std::endl;

    List2[1] = "Hello";
    for(int i = 0; i < List2.size(); ++i){
        std::cout << List2[i] << " ";
    }
    std::cout << std:: endl;

    List2.converse();
    List2.traverse(Print); std::cout << std::endl;
}
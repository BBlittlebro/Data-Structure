#include <iostream>
#include <exception>
#include <queue>

template <class T>
class Queue{
    struct Node{
        T data;
        Node *next;
    };
    Node *front_;
    Node *rear;
public:
    Queue();
    bool push(T e);
    bool pop();
    T& front();
    bool empty();
};

template <class T>
Queue<T>::Queue(){
    front_ = rear = new Node();
    if(!front_) printf("記憶體分配錯誤!\n");
    front_->next = 0;
}

template <class T>
bool Queue<T>::push(T e){
    Node *p = new Node();
    if(!p) return false;
    p->data = e;
    p->next = 0;
    rear->next = p;
    rear = p;
    return true;
}

template <class T>
bool Queue<T>::pop(){
    if(front_ == rear) return false;
    Node *temp = front_->next;
    front_->next = temp->next;
    if(temp == rear) rear = front_;
    delete temp;
    return true;
}

template <class T>
T& Queue<T>::front(){
    if(front_ == rear) printf("空陣列\n");
    return front_->next->data;
}

template <class T>
bool Queue<T>::empty(){
    return rear == front_;
}

int main(){
    //Queue<int> Q;
    std::queue<int> Q;
    Q.push(10);
    Q.push(8);
    Q.push(6);
    printf("%d\n", Q.front());
    Q.pop();
    printf("%d\n\n", Q.front());
    
    Q.push(4);
    Q.push(2);
    while(!Q.empty()){
        printf("%d\n", Q.front());
        Q.pop();
    }
}
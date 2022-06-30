#include <iostream>

template <class T>
class SqQueue{
    T *data;
    int front_, rear_, capacity;
public:
    SqQueue(int cap = 5){
        data = new T[cap];
        if(!data) printf("記憶體分配錯誤!\n");
        front_ = 0;
        rear_ = 0;
        capacity = cap;
    }
    bool push(T e){
        if((rear_+1) % capacity == front_){    //full
            expand();
            printf("new space!\n");
        }
        data[rear_] = e;
        rear_ = (rear_ + 1) % capacity;
        return true;
    }
    bool pop(){
        if(rear_ == front_){
            printf("Its empty!\n");
            return false;
        }
        front_ = (front_ + 1) % capacity;
        return true;
    }
    T& front(){
        if(front_ == rear_){
            printf("Its empty!\n");
        }
        return data[front_];
    }
    T& rear(){
        if(front_ == rear_){
            printf("Its empty!\n");
        }
        return data[(rear_ - 1 + capacity) % capacity];
    }
    bool empty(){
        return (rear_ == front_);
    }
    int size(){
        return (rear_ - front_ + capacity) % capacity;
    }
    void clear(){
        front_ = rear_ = 0;
    }
    void expand(){
        T *temp = new T[2*capacity];
        if(!temp) printf("記憶體分配錯誤!\n");
        int index = front_;
        int new_index = 0;
        while(index != rear_){
            temp[new_index] = data[index];
            index = (index + 1) % capacity;
            new_index += 1;
        }
        delete[] data;
        data = temp;
        capacity *= 2;
        front_ = 0;
        rear_ = new_index;
        
    /*
        for(int i = 0; i < capacity; ++i){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity *= 2;
    */
        return;
    }
};

int main(){
    SqQueue <int> Sq;
    Sq.push(1);
    Sq.push(2);
    Sq.push(3);
    Sq.push(4);
    Sq.pop();
    Sq.push(5);
    Sq.pop();
    Sq.push(100);
    Sq.push(200);
    Sq.push(300);
    printf("last: %d \n", Sq.rear());
    while(!Sq.empty()){
        printf("%d ", Sq.front());
        Sq.pop();
    }
    printf("\n");
}
template <class T>
class Queue{
    struct Node{
        T data;
        Node *next;
    };
    Node *front;
    Node *rear;
public:
    Queue(){
        front = rear = new Node();
        if(!front) throw "記憶體分配錯誤!\n";
        front->next = 0;
    }
    bool push(T e){
        Node *p = new Node();
        if(!p) return false;
        p->data = e;
        p->next = 0;
        rear->next = p;
        rear = p;
        return true;
    }
    bool pop(){
        if(front == rear) return false;
        Node *temp = front->next;
        front->next = temp->next;
        if(temp == rear) rear = front;
        delete temp;
        return true;
    }
};

int main(){}
#include <iostream>

template <class T>
class SqList{
    T *data;
    int capacity, n;
public:
    SqList(int cap = 3){
        data = new T[cap];
        if(!data) throw "SqList 分布記憶體錯誤!";
        capacity = cap; n = 0;
    }
    bool insert(int i, T e){
        if(i < 1 || i > n+1){return false;}
        if(n == capacity)
            if(!realloc()) return false;
    /*    
        T *p, *q;
        p = &data[i-1];
        q = &data[n];
        for(;q > p; q--){
            *q = *(q-1);
        }
    */
        for(int j = n; j >= i; --j){
            data[j] = data[j-1];
        }
        data[i-1] = e; ++n;
        return true;
    }
    bool remove(int i){
        if(i < 1 || i > n){return false;}
    /*
        T *p, *q;
        p = data + i - 1;
        q = data + n - 1;
        for(;p < q; ++p){
            *p = *(p+1);
        }
    */
    
        for(int j = i; j < n; ++j){
            data[j-1] = data[j];
        }
        --n;
        return true;
    }
    bool push_back(T e){
        if(n == capacity)
            if(!realloc()) return false;
        data[n] = e; ++n;
        return true;
    }
    bool insert_front(T e){
        insert(1, e);
    }
    bool get(int i, T &e){
        if(i < 1 || i > n) {return false;}
        e = data[i-1]; return true;
    }
    bool set(int i, T e){
        if(i < 1 || i > n) {return false;}
        data[i-1] = e; return true;
    }
    int size(){return n;}
    bool pop_back(){
        if(n == 0) return false;
        n--;
        return true;
    }
    bool remove_front(){
        for(int j = 1; j < n; ++j){
            data[j-1] = data[j];
        }
        --n;
        return true;
    }
    int find(int pos, T e){
        for(int i = pos; i <= n; ++i){
            if(data[i-1] == e){
                return i;
            }
        }
        std::cout << "Not find.\n";
        return 0;
    }
    int find(int pos, bool (*cmp) (T &e)){
        for(int i = pos; i <= n; ++i){
            if(cmp(data[i-1])){
                return i;
            }
        }
        std::cout << "Not find.\n";
        return 0;
    }
    void traverse( void (*fp) (T &e)){      //掃過一次
        for(int i = 1; i <= n; ++i){
            fp(data[i-1]);
        }
        //std::cout << std::endl;
    }
private:
    bool realloc(){
        T *p = new T[2 * capacity];
        if(!p) return false;
        for(int i = 0; i < n; ++i){
            p[i] = data[i];
        }
        delete[] data;
        data = p;
        capacity *= 2;
        return true;
    }
};

template <class T>
void print(SqList<T> &L){
    T temp;
    for(int i = 1; i <= L.size(); ++i){
        L.get(i, temp);
        std::cout << temp << " ";
    }
    std::cout << std::endl;
}

void Print(char &ch){
    std::cout << ch << " ";
}
void Print(int &ch){
    std::cout << ch << " ";
}
void Converse(char &ch){
    if(ch >= 'A' && ch <= 'Z'){
        ch -=('A' - 'a');
    }
}
bool LagerB(char &ch){
    if(ch > 'B') return true;
    return false;
}

#include <string>
struct student{
    std::string name;
    double score;
    student(std::string n = "no", double s = 0): name(n), score(s) {}
};
void Print(student &person){
    std::cout << person.name << ": " << person.score;
    std::cout << std::endl;
}

std::ostream & operator << (std::ostream &os, student &person){
    os << person.name << ": " << person.score << std::endl;
    return os;
}

int main(){
    SqList<char> list;
    char ch;
    if(!list.get(1, ch)){
        std::cout << "Not find.\n";
    }else{
        std::cout << ch << std::endl;
    }
    list.push_back('A'); print(list);
    list.push_back('B'); print(list);
    list.push_back('C'); print(list);
    list.push_back('D'); print(list);
    list.set(2, 'H'); print(list);
    list.insert(2, 'K'); print(list);
    list.remove(2); print(list);
    list.pop_back(); print(list);
    list.insert(1, 'Q'); print(list);
    list.remove_front(); print(list);
    list.insert(2, 'A'); print(list);
    list.insert(5, 'A'); //print(list);
    list.traverse(Print); std::cout << std::endl;
    for(int p = 1; p <= list.size();){
        int i = list.find(p, 'A');
        if(i >= 0){
            std::cout << "A 的位置是 " << i << std::endl;
        }
        p = i + 1;
    }
    int i = list.find(1, LagerB);
    if(i >= 0){
        std::cout << "比 B 大的位置是 " << i << std::endl;
    }
    list.remove(5); print(list);

    list.traverse(Converse); 
    list.traverse(Print); std::cout << std::endl;

    SqList<int> ints;
    ints.push_back(23);
    ints.push_back(33);
    ints.push_back(43);
    ints.push_back(53);
    ints.insert(2, 56); 
    ints.traverse(Print); std::cout << std::endl;

    SqList<student> students;
    students.push_back(student("Andy", 100));
    students.push_back(student("Cock", 60.5));
    students.push_back(student("Sora", 55.7));
    students.traverse(Print);
    //print(students);
}
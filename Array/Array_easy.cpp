#include <iostream>

template <class T>
class Array{
public:
    T *data;
    int n;
    int *bounds;
    int *constants;
};

template <class T>
int InitArray(Array<T> *A, int n, ...){
    if(n < 1){
        printf("初始化維度錯誤\n");
        return -2;
    }
    A->n = n;
    A->bounds = (int*) malloc (n*sizeof(int));
    if(!A->bounds){
        printf("記憶體空間不足\n");
        return -1;
    }

    int total = 1;      //元素總數
    va_list ap;         //可變參數列的儲存清單
    va_start(ap, n);    //從哪個固定參數後接收可變參數
    for(int i = 0; i < n; ++i){
        A->bounds[i] = va_arg(ap, int);     //從清單取出一個 int 型態的參數
        if(A->bounds[i] <= 0){
            printf("維度不可為負數\n");
            return -1;
        }
        total *= A->bounds[i];
    }
    va_end(ap);         //清單結束
    A->data = (T*) malloc (total*sizeof(T));
    if(!A->data){
        printf("記憶體空間不足\n");
        return -2;
    }

    A->constants = (int*) malloc (n*sizeof(int));
    if(!A->constants){
        printf("記憶體空間不足\n");
        return -3;
    }
    A->constants[n-1] = 1;
    for(int i = n-2; i >= 0; --i){
        A->constants[i] = A->constants[i+1] * A->bounds[i+1];
    }
    return 0;
}

template<class T>
int Value(Array<T> A, T *e, ...){
    int off = 0;
    va_list ap;
    va_start(ap, e);
    for(int i = 0; i < A.n; ++i){
        int j = va_arg(ap, int);
        if(j < 0 || j >= A.bounds[i]){
            printf("超出維度範圍");
            return -1;
        }
        off += A.constants[i] * j;          //直接找到那個元素位置
    }
    va_end(ap);
    *e = *(A.data + off);
    return 0;
}

template<class T>
int Assign(Array<T> A, T e, ...){
    int off = 0;
    va_list ap;
    va_start(ap, e);
    for(int i = 0; i < A.n; ++i){
        int j = va_arg(ap, int);
        if(j < 0 || j >= A.bounds[i]){
            printf("超出維度範圍");
            return -1;
        }
        off += A.constants[i] * j;          //直接找到那個元素位置
    }
    va_end(ap);
    *(A.data + off) = e;
    return 0;
}

template <class T>
void Destroy(Array<T> *A){
    free(A->data);
}


int main(){
    Array<int> A;
    InitArray(&A, 2, 3, 4);
 
    int e = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j){
            Assign(A, e, i, j);
            e++;
        }
    }

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j){
            Value(A, &e, i, j);
            printf("%2d ", e);
        }
        printf("\n");
    }

    Array<int> B;
    InitArray(&B, 3, 5, 4, 7);
    e = 100;
    Assign(B, e, 3, 1, 2);
    Value(B, &e, 3, 1, 2);
    printf("%2d\n", e);

    Destroy(&A);
    Destroy(&B);
    return 0;
}
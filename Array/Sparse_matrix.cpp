#include <vector>
#include <iostream>

//稀疏矩陣加上轉置矩陣

template <typename T>
class Matrix{
    struct Triple{
        int i, j;
        T e;
    };
    std::vector<Triple> data;
    int mu, nu, tu = 0;  //行、列、元素個數
public:
    Matrix() = default;
    Matrix(int m, int n, int t = 0): mu(m), nu(n){
        if(t) {tu = t; data.resize(t);}
    }
    Triple & operator[](int i){
        return data[i];
    }
    Triple & operator[](int i) const {
        return data[i];
    }
    void resize(int s) {data.resize(s); tu = data.size();}
    int size() {return data.size();}
    void print(){
        for(int i = 0; i < size(); ++i){
            std::cout << data[i].i << "." << data[i].j
            << "." << data[i].e << std::endl;
        }
    }
    template<typename S>
    friend void Transpose(const Matrix<S> &M, Matrix<S> &G);
};

//稀疏矩陣複雜度 O(nu * tu)，最糟是當tu = nu * mu => O(nu^2 * mu)，
//比一般矩陣複雜度 O(nu * mu)還糟糕。
template<typename S>
void Transpose(const Matrix<S> &M, Matrix<S> &G){                    
    G.mu = M.nu; G.nu = M.mu; G.tu = M.tu;
    G.data.resize(G.tu);
    if(G.tu){
        int q = 0;
        for(int col = 1; col <= M.mu; ++col){           //看 mu 下面就看 i
            for(int p = 0; p < M.tu; ++p){
                if(M.data[p].i == col){
                    G.data[q].i = M.data[p].j;
                    G.data[q].j = M.data[p].i;
                    G.data[q].e = M.data[p].e;
                    q++;
                }
            }
        }
    }
    return;
}

//快速轉置矩陣複雜度 O(nu + tu)，最糟是當tu = nu * mu => O(mu * nu)，
//跟一般轉置的複雜度一樣
template<typename S>
void FastTranspose(const Matrix<S> &M, Matrix<S> &G){
    G.mu = M.nu; G.nu = M.mu; G.tu = M.tu;
    G.data.resize(G.tu);
    int num[M.tu];
    int cpot[M.tu];
    if(G.tu){
        for(int col = 0; col < M.nu; ++col){    //初始化
            num[col] = 0;
        }
        for(int t =  0; t < M.tu; ++t){         //計算每列有幾個元素
            num[M.data[t].j]++;
        }

        cpot[0] = 1;
        for(int col = 1; col < M.tu; ++col){
            cpot[col] = cpot[col-1] + num[col-1];
        }
        for(int p = 0; p < M.tu; ++p){
            int col = M.data[p].j;
            int q = cpot[col];
            G.data[q].i = M.data[p].j;
            G.data[q].j = M.data[p].i;
            G.data[q].e = M.data[p].e;
            cpot[col]++;
        }
    }

    return;
} 

int main(){
    Matrix<int> M(3,4,3);
    M[0].i = 1; M[0].j = 2; M[0].e = 12;
    M[1].i = 2; M[1].j = 4; M[1].e = -7;
    M[2].i = 3; M[2].j = 3; M[2].e = 9;
    M.print();
    
    std::cout << "轉置矩陣" << std::endl;
    Matrix <int> G;
    Transpose(M, G);
    G.print();

    std::cout << "快速轉置矩陣" << std::endl;
    Matrix <int> L;
    Transpose(M, L);
    L.print();
    return 0;
}
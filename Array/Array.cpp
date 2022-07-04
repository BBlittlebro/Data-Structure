#include <iostream>

template <class T>
class Array{
private:
    std::unique_ptr<T[]> data;
    std::unique_ptr<int[]> bounds;
    std::unique_ptr<int[]> constants;
    int dim{0}, size{1};
public:
    Array() = default;
    template<typename... Ns>
    Array(Ns... ds){
        (size *= ... *= ds);
        dim = sizeof ...(ds);
        bounds = std::unique_ptr<int[]>(new int [dim]);     //會自動 delete
        constants = std::unique_ptr<int[]>(new int [dim]);
        int d = 0;
        ([&](const auto & x) {bounds[d] = x; d++;} (ds), ...);  // x 就是 ds 數組
        
        constants[dim - 1] = 1;
        for(int i = dim- 2 ; i >= 0; --i){
            constants[i] = bounds[i+1] * constants[i+1];
        }
        data = std::unique_ptr<T[]>(new T[size]);
    }

    template<typename... Ns>
    T& operator() (Ns... js) const{
        auto idx = 0;
        auto d = 0;
        ([&](const auto& ji) {idx += constants[d] * ji; d++;} (js), ...);
        return data[idx];
    }

    template<typename... Ns>
    T& operator() (Ns... js){
        auto idx = 0;
        auto d = 0;
        ([&](const auto& ji) {idx += constants[d] * ji; d++;} (js), ...);
        return data[idx];
    }
};



int main(){
    Array<double> A(2,3,4);
    A(0,1,2) = 37;
    std::cout << A(0, 1, 2) << std::endl;
    Array<double> B(3,4);

    int k = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j){
            B(i, j) = k++;
        }
    }

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j){
            std::cout << B(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
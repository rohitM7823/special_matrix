#include<iostream>
#include"matrix.hpp"
using namespace std;

int main(){
    Matrix* ob_t;
    int size, dim;
    cin>>size;
    dim = size;
    ob_t = new Matrix(size);

    for(int i=1; i<=size; ++i){
        for(int j=1; j<=size; ++j)
            Matrix::setValueUpper(ob_t, size, i, j, i+j);
    }

    print_all(ob_t, size, dim);

    cout << endl;
    system("pause");
    return EXIT_SUCCESS;
}

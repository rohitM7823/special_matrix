#include <iostream>
#include "matrix.hpp"
using namespace std;

int main(){
    Matrix* ob_i;
    int size;
    cin>>size;

    ob_i = new Matrix(size);
    cout << endl;

    for(int i=1; i<=size; ++i){
        for(int j=1; j<=size; ++j)
            Matrix::setValueLower(ob_i, i, j, i+j);
    }

    print_all(ob_i, size);

    cout<<endl;
    system("pause");
    return EXIT_SUCCESS;
}
#include <iostream>
#include "formula.hpp"

class Matrix{
    int* ar = new int[10];
    int d;

public:
    Matrix(){};
    Matrix(int dim) : d{dim} {}

    static void setValue(Matrix* ob, int row, int col, int elm){
        if(row == col){
            ob->ar[row-1] = elm;
        }
    } 

    static int& getValue(Matrix* ob, int row, int col){

        static int tmp=0;
        if(row == col) return ob->ar[row-1];
        else return tmp;
    }


    static void 
    printMatrix(Matrix* ob){
        
        for(int i=0; i<ob->d; ++i){
            for(int j=0; j<ob->d; ++j){
                
                if(i==j) std::cout << ob->ar[j] <<" ";
                else std::cout << "0 ";
            }
            std::cout << std::endl;
        }
    }

    

    ~Matrix(){
        delete ar;
    }

};


int main(){
    Matrix* en_o = new Matrix(5); 
    Matrix* en_t = new Matrix(5);

    /* Matrix::setValue(en_o, 2, 2, 350);
    int& elm = Matrix::getValue(en_o, 2, 2); // Value at specific palce.

    std::cout << elm << std::endl;

    Matrix::setValue(en_t, 2, 2, 675);
    int& elemt = Matrix::getValue(en_t, 2, 2);

    std::cout << elemt << std::endl; */

    std::cout << "Diagonal Matrix EX - 1" << std::endl;
    for(int i=1; i<=5; ++i)
        Matrix::setValue(en_o, i, i, rand());

    Matrix::printMatrix(en_o);
    
    std::cout << std::endl;

    std::cout << "Diagonal Matrix EX - 2" << std::endl;
    for(int i=1; i<=5; ++i)
        Matrix::setValue(en_t, i, i, rand());

    Matrix::printMatrix(en_t);

    delete en_o, en_t;
    std::cout << std::endl;

    system("pause");
    return EXIT_SUCCESS;
}
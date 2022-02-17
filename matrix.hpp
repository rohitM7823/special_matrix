#include <iostream>
#include "formula.hpp"

class Matrix:protected Formulas{
    int d;
    int* ary;
    
public:
    Matrix(int dim){
        d = dim;
        ary = new int[size(dim)];
    }

    static void setValueLower(Matrix* ob, int i, int j, int num){
        if(i>=j) ob->ary[row_major_lower(i-1, j-1)] = num;
    }

    static void setValueLower(Matrix* ob, int d, int i, int j, int num){
        if(i>=j) ob->ary[col_major_lower(d, i-1, j-1)] = num;
    }

    static void setValueUpper(Matrix* ob, int i, int j, int num){
        if(i<=j) ob->ary[col_major_upper(i-1, j-1)] = num;
    }

    static void setValueUpper(Matrix* ob, int d, int i, int j, int num){
        if(i<=j) ob->ary[row_major_upper(d, i-1, j-1)] = num;
    }

    static int getValue(Matrix* ob, int i, int j){
        if(i>=j) return ob->ary[row_major_lower(i-1, j-1)]; 
        else return 0;
    }

    static int getValue(Matrix* ob, int d, int i, int j){
        if(i<=j) return ob->ary[row_major_upper(d, i-1, j-1)]; 
        else return 0;
    }

    friend void print_all(Matrix* ob, int d);
    friend void print_all(Matrix*ob, int range, int d);

    ~Matrix(){
        delete[] ary;
    }

};

void print_all(Matrix*ob, int d){
    for(int row = 1; row <= d; ++row){
        for(int col = 1; col <= d; ++col)
            std::cout << ob->getValue(ob, row, col) << " ";
        std::cout << std::endl;
    }
}

void print_all(Matrix*ob, int range, int d){
    for(int row=1; row<=range; ++row){
        for(int col=1; col<=range; ++col)
            std::cout << ob->getValue(ob, d, row, col) << " ";
        std::cout << std::endl;
    }
}
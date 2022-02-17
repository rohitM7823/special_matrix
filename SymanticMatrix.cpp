#include "matrix.hpp"
#include <iostream>
using namespace std;

class Symantic:public Formulas{
    int* ary = new int[size(5)];
public:
    void setValueLower(int i, int j, int value=0){
        if(j>=i) ary[row_major_lower(i-1, j-1)] = i;
        else if(i>=j) ary[row_major_lower(i-1, j-1)] = j;
    }

    int getValueLower(int i, int j){
        if(j>=i) ary[row_major_lower(i-1, j-1)];
        return ary[row_major_lower(i-1, j-1)];
    }

    friend void print_all(Symantic ob);

};

void print_all(Symantic ob){
    for(int row=1; row<=5; ++row){
        for(int col=1; col<=5; ++col){
            cout << ob.getValueLower(row, col) << " ";
        }
        cout<<endl;
    }
}

int main(){
    Symantic mat;

    for(int row=1; row<=5; ++row){
        for(int col=1; col<=5; ++col){
            mat.setValueLower(row, col);
        }
    }

    print_all(mat);
    cout<<endl;
    system("pause");
    return EXIT_SUCCESS;
}


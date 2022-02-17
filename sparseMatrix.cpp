#include <iostream>
using namespace std;

struct coordinates{
    int row = 0;
    int col = 0;
    int elemt = 0;
};

struct Sparse{
    int totalRow=0, totalCol=0, totalEle=0;
    struct coordinates* ptr = nullptr;
}m;

bool inputFunc(Sparse &ref){

    try {
        cout << "Enter Dimensions: ";
        cin >> ref.totalRow >> ref.totalCol;
        cout << "\nEnter Total Non-Zero Elements: ";
        cin >> ref.totalEle;
    }
    catch(exception e) {
        cout << "Enter All Details Correctly.";
        return false;
    }
    
    return true;
}

Sparse createSparse(){

    bool check = inputFunc(m);

    if(check == true){
        m.ptr = new coordinates[m.totalEle];

        for(int i=0; i<m.totalEle; i++){
            cout << "Enter Coordinates: ";
            cin >> m.ptr[i].row >> m.ptr[i].col;
            cout << "\nEnter Non-Zero Element: ";
            cin >> m.ptr[i].elemt;
        }
    }
    else exit(1);

    return m;
}

void printSpraseMarix(Sparse* x){
    int e=0;

    for(int i=1; i<=x->totalRow; i++){

        for(int j=1; j<=x->totalCol; j++){

            if( i == x->ptr[e].row && j == x->ptr[e].col ){
                cout << " " << x->ptr[e++].elemt;
            }
            else cout << " 0";
        }

        cout << endl;
    }

}

Sparse* addition(Sparse* a, Sparse* b){

    Sparse* t = new Sparse;
    int i=0, j=0, k=0;

    if(a->totalRow != b->totalRow || a->totalCol != b->totalCol) return 0;
    else{
        
        t->ptr = new coordinates[a->totalEle+b->totalEle];

        while(i<a->totalEle && j<b->totalEle){

            if(a->ptr[i].row < b->ptr[j].row)
                t->ptr[k++] = a->ptr[i++];

            else if(a->ptr[i].row > b->ptr[j].row)
                t->ptr[k++] = b->ptr[j++];

            else{

                if(a->ptr[i].col < b->ptr[j].col)
                    t->ptr[k++] = a->ptr[i++];

                else if(a->ptr[i].col > b->ptr[j].col)
                    t->ptr[k++] = b->ptr[j++];

                else{
                    t->ptr[k] = a->ptr[i];
                    t->ptr[k++].elemt = a->ptr[i++].elemt + b->ptr[j++].elemt;
                } 
                
            }
        }

        for(; i<a->totalEle; i++)
            t->ptr[k++] = a->ptr[i];

        for(; j<b->totalEle; j++)
            t->ptr[k++] = b->ptr[j];

        
        t->totalRow = a->totalRow;
        t->totalCol = a->totalCol;
        t->totalEle = k;
   }

    return t;
}


int main(){
   Sparse fst = createSparse();
   Sparse secd = createSparse();

   Sparse* result = addition(&fst, &secd); 

   printSpraseMarix(result); 
   
   delete result;
   system("pause");
   return EXIT_SUCCESS;
}
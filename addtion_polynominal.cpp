#include <iostream>
#include <cmath>
using namespace std;

struct terms{
    int cofe;
    int exp;
};

class Polynominal{
    
public:
    
    int totalTerms;
    terms *tms = nullptr;

    Polynominal(){}
    Polynominal(int): totalTerms{0} {}

    Polynominal* createP(){

        cout << "Enter Total no of Terms: ";
        cin >> totalTerms;       

        tms = new terms[totalTerms];
        for(int i=0; i<totalTerms; ++i){
            cout << "Enter " << i+1 <<" Cooeffiecient: ";
            cin >> tms[i].cofe;
            cout << "Enter " << i+1 << " Exponent: ";
            cin >> tms[i].exp;
        }

        return this;
    }
        
    void showMatrix(){
        long addT = 0;

        for(int i=0, ep; i<totalTerms; ++i){
            ep = pow(2, tms[i].exp);
            addT += tms[i].cofe * ep;
        }

        cout << addT << endl;
    }

    friend Polynominal* additionPolynominal(Polynominal, Polynominal);    
};

Polynominal* additionPolynominal(Polynominal* a, Polynominal* b){
        int i=0, j=0, k=0;
        Polynominal *sum = new Polynominal();

        sum->tms = new terms[a->totalTerms + b->totalTerms];

        while( i < a->totalTerms && j < b->totalTerms ){

            if(a->tms[i].exp > b->tms[j].exp)
                sum->tms[k++] = a->tms[i++];

            else if(a->tms[i].exp < b->tms[j].exp)
                sum->tms[k++] = b->tms[j++];

            else{

                sum->tms[k] = a->tms[i];
                sum->tms[k++].cofe = a->tms[i++].cofe + b->tms[j++].cofe;

            }

        }

        for(; i<a->totalTerms; ++i)
            sum->tms[k++] = a->tms[i];

        for(; j<b->totalTerms; ++j)
            sum->tms[k++] = b->tms[j];

        sum->totalTerms = k;

        return sum;
}

int main(){
    Polynominal* poly1 = new Polynominal();
    Polynominal* poly2 = new Polynominal();

    Polynominal* p1 = poly1->createP();
    Polynominal* p2 = poly2->createP();

    Polynominal* p3 = additionPolynominal(p1, p2);


    p3->showMatrix();

    system("pause");
    return 0;
}
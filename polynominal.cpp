#include<iostream>
#include<cmath>
using namespace std;

struct terms{
    int coe;
    int exp;
};

class PolyM{
    int x;
    int totalTerms;
    terms* tms = nullptr;
public:
    PolyM():x{0}, totalTerms{0}{}

    void inputTerms(){
        cout<<"Enter Total Number of Terms: ";
        cin >> totalTerms;

        tms = new terms[totalTerms];
        cout << "Enter Value of X: ";
        cin >> x;
        for(int i=0; i<totalTerms; ++i){
            cout << "\nEnter Coefficient " << i+1 << ": ";
            cin >> tms[i].coe;
            cout << "\nEnter Exponent " << i+1 << ": ";
            cin >> tms[i].exp;
        }

        cout << "You Have Entered all Necessary Details.." << endl;
    }

    int termsAddition(){
        int sum = 0, p;

        for(int i=0; i<totalTerms; ++i){
            p = pow(x, tms[i].exp); 
            sum+=tms[i].coe*p;
        }

        return sum;
    }
    
};

int main(){

    PolyM* p = new PolyM();

    p->inputTerms();
    int result = p->termsAddition();

    cout << "\nAddition of Terms: " << result << endl;

    system("pause");
    return 0;

}


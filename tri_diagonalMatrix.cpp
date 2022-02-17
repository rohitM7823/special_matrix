#include <iostream>
using namespace std;

class Tri_Diagonal{
	int* elements = nullptr;
protected:
	int dim;	
public:
	Tri_Diagonal(int d){
		this->dim = d;
		elements = new int[3*dim-2];
	}

	void setValue(int row, int col, int value){
		if((row - col) == 0) // Main Diagonal
			elements[(dim-1)+(row-1)] = value;
		else if((row - col) == 1) // Lower Diagonal
			elements[row-1] = value;
		else if((row - col) == -1) // Upper Diagonal
			elements[(dim-1)+(row-1)] = value;
		else 0;
	}

	int getValue(int row, int col){
		if((row - col) == 0) // Main Diagonal
			return elements[(dim-1)+(row-1)];
		else if((row - col) == 1) // Lower Diagonal
			return elements[row-1];
		else if((row - col) == -1) // Upper Diagonal
			return elements[(dim-1)+(row-1)];
		else return 0;
		
	}

	friend void printMatrix(Tri_Diagonal);
};

void printMatrix(Tri_Diagonal ob){
	for(int i=1; i<=ob.dim; i++){
		for(int j=1; j<=ob.dim; j++)
			cout<< ob.getValue(i, j)<< " ";
		cout << endl;
	}
}

int main(){
	int dimen;
	cin >> dimen;

	Tri_Diagonal matrix(dimen);

	for(int i=1; i<=dimen; i++){
		for(int j =1; j<=dimen; j++)
			matrix.setValue(i,j, 1);		
	}
	
	printMatrix(matrix);
	system("pause");

	return 0;
}
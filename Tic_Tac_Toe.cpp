#include <iostream>
using namespace std;

int arr[3][3] = {0};

void matrixGen(){
	// This function generates index for Tic Tac Toe array
	int count = 1;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			arr[i][j] = count;
			count ++;
		}
	}
}

void matrixDisp(){
	// Displaying the Tic Tac Toe array
	for (int i = 0; i < 3; i++){
		cout << endl;
		for (int j = 0; j < 3; j++) cout <<"  "<< arr[i][j];
	}
}

bool CharInvert(bool mark){
	if (mark == true) mark = false;
	else mark = true;
	return mark;
}

void inputMatrix(){
	int num = 0;
	bool mark = true, flag = false, cut =  false;
	char cross = 'X', circle = 'O', curChar;
	while(flag != true){
		mark = CharInvert(mark); 
		if (mark == true) curChar = cross;
		else curChar = circle;
		matrixDisp();
		cout <<"\n "<< curChar <<"'s turn \n Enter the Index Number: ";
		cin >> num;
		for (int i = 0 ; i <= 2; i++){
			for (int j = 0; j <= 2 ; j++){
				if (arr[i][j] == num){
					arr[i][j] = curChar;
					cut = true;
					break;
				}
				cout <<" i = "<< i <<" j = "<<j<<"\n";
			}
			if (cut == true) break;
			if (i == 2) flag = true;
		}
	}
}



int main(){
    
	std::cout <<"\n Generating Index for Matrix !" << std::endl;
	matrixGen();
	cout <<"\n Matrix Index Generated Succesfully !" << endl;
	matrixDisp();
	cout <<"\n Initializing Input Stream !";
	inputMatrix();
	matrixDisp();
	
	return 0;
}
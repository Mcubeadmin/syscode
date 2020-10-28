#include <iostream>
using namespace std;

int arr[3][4] = {0};
char cross = 'X', circle = 'O';
bool mark;

//Matrix Index Generation Function
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

//Matrix Display Function
void matrixDisp(){
	// Displaying the Tic Tac Toe array
	for (int i = 0; i < 3; i++){
		cout << endl;
		for (int j = 0; j < 3; j++) cout <<"  "<< arr[i][j];
	}
}

//Turn Selection Function
char CharInvert(){
	if (mark == true){
		mark = false;
		return cross;
	}
	else{
		mark = true;
		return circle;
	}
	
}

bool checker(int* num, bool* mark, char* curChar){
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2 ; j++){
			if (arr[i][j] == *num) arr[i][j] = *curChar;
			if (*mark == true){
				if (arr[i][j] < 10) *mark = false;
			}
		}
	}
	return *mark;
}

//Input Stream Function
void MatrixInput(){
	bool mark = false;
	int num = 0;
	while (mark == false){
		mark = true;
		char curChar = CharInvert();
		cout << "\n " << curChar << "'s Turn now !" << endl;
		cout <<"\n Enter the Index : ";
		cin >> num;
		mark = checker(&num, &mark, &curChar);
		system("cls");
		matrixDisp();
	}
}



int main(){
    
	cout <<"\n Generating Index for Matrix !" << endl;
	matrixGen();
	cout <<"\n Matrix Index Generated Succesfully !" << endl;
	matrixDisp();
	cout <<"\n Initializing Input Stream !";
	MatrixInput();
	
	return 0;
}
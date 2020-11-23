#include <iostream>
using namespace std;

int arr[3][4] = {0};
char cross = 'X', circle = 'O', curChar, winner = '0';
bool flip;

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
		for (int j = 0; j < 3; j++){
			if (arr[i][j] == 79) cout <<"  "<< 'O';
			else if (arr[i][j] == 88) cout <<"  "<< 'X';
			else cout <<"  "<< arr[i][j];
		}
	}
}

//Turn Selection Function
char CharInvert(){
	if (flip == true){
		flip = false;
		return cross;
	}
	else{
		flip = true;
		return circle;
	}
	
}

char algoMain(bool* mark){
	int i = 0, j = 0;
	if (arr[i][j] == arr[i+1][j+1]){
			if (arr[i+1][j+1] == arr[i+2][j+2]){
				*mark = true;
				return arr[i][j];
			}
		}
		if (arr[i][j+2] == arr[i+1][j+1]){
			if (arr[i+1][j+1] == arr[i+2][j]){
				*mark = true;
				return arr[i][j+2];
			}
		}
	for (i; i <= 2; i++){
		j = 0;
		if (arr[i][j] == arr[i][j+1]){
			if (arr[i][j+1] == arr[i][j+2]){
				*mark = true;
				return arr[i][j];
			}
		}
		if (arr[j][i] == arr[j+1][i]){
			if (arr[j+1][i] == arr[j+2][i]){
				*mark = true;
				return arr[j][i];
			}
		}	
		
		if (*mark == true) break;
	}
	return '0';
}

bool checker(int* num, bool* mark, char* curChar){
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2 ; j++){
			if (arr[i][j] == *num){
				arr[i][j] = *curChar;
				*curChar = CharInvert();
			}
			if (*mark == true){
				if (arr[i][j] < 10) *mark = false;
			}
		}
	}
	return *mark;
}

//Input Stream Function
void MatrixInput(){
	cout <<" Initializing Input Stream !";
	cout <<" Game Ready ! "<< endl;
	matrixDisp();
	bool mark = false;
	int num = 0;
	curChar = CharInvert();
	while (mark == false){
		mark = true;
		cout << "\n " << curChar << "'s Turn now !" << endl;
		cout <<"\n Enter the Index : ";
		cin >> num;
		system("cls");
		cout <<"\n\t\t MCUBE COMPUTING SYSTEMS \n\t\t Tic Tac Toe ";
		cout <<"\n Generating Index for Matrix !" << endl;
		mark = checker(&num, &mark, &curChar);
		winner = algoMain(&mark);
		matrixDisp();
		if (winner == '0' && mark == true) cout <<"\n This Game is a Tie !";
		else if (winner == '0') continue;
		else cout <<"\n The winner is "<< winner; 
	}
}



int main(){
    char button = 'a';
	while (button == 'a'){
		system("cls");
		cout <<"\n\t\t MCUBE COMPUTING SYSTEMS \n\t\t Tic Tac Toe ";
		cout <<"\n Generating Index for Matrix !  ";
		matrixGen();
		cout <<" Matrix Index Generated Succesfully !";
		MatrixInput();
		cout <<"\n Enter 'a' for new game \n Enter 'e' to exit : ";
		cin >> button; 
		if (button == 'a') continue;
		if (button == 'e') break;
	}
	
	return 0;
}
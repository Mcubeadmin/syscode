#include <iostream>
using namespace std;

//Global Variables
int arr[3][4] = {0};
char cross = 'X', circle = 'O', winner = '0';


//Matrix Index Generation Function
void matrixGen(){
	// This function generates index numbers for Tic Tac Toe array (1 to 9)
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
	cout << "   1  2  3";
	for (int i = 0; i < 3; i++){
    cout << endl;
    
	cout << i + 1;
		for (int j = 0; j < 3; j++){
      		
			if (arr[i][j] == 79) cout <<"  "<< 'O';		//ASCII 79 is O
			else if (arr[i][j] == 88) cout <<"  "<< 'X';//ASCII 88 is X
			else cout <<"  *";
		}
	}
	cout << endl;
}


//this is the main game algorithm 
char algoMain(bool* mark){
	int i = 0, j = 0;

	//diagonal checking 
	if (arr[0][0] == arr[1][1]){
		if (arr[1][1] == arr[2][2]){
			*mark = true;
			return arr[0][0];
		}
	}
	
	if (arr[0][2] == arr[1][1]){
		if (arr[1][1] == arr[2][0]){
			*mark = true;
			return arr[0][2];
		}
	}
	
	//row and column checking
	for (; i <= 2; i++){
		j = 0;

		//horizontal checking 
		if (arr[i][j] == arr[i][j+1]){
			if (arr[i][j+1] == arr[i][j+2]){
				*mark = true;
				return arr[i][j];
			}
		}
		//vertical checking
		if (arr[j][i] == arr[j+1][i]){
			if (arr[j+1][i] == arr[j+2][i]){
				*mark = true;
				return arr[j][i];
			}
		}	
	}

	return '0';
}

//this function replaces the array element with input 
void checker(int* num, bool* mark, char* curChar){
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2 ; j++){
			if (arr[i][j] == *num){ 		//searching the number
				arr[i][j] = *curChar;		//replacing

				if (*curChar == cross) *curChar = circle;	//inverting the turn of player (O or X)
				else *curChar = cross;
			}

			if (*mark == true){				
				if (arr[i][j] < 10) *mark = false; //if true, game did not end
			}
		}
	}
}

//Input Stream Function
void MatrixInput(){
	bool mark = false;
	int num = 0;
	char curChar = cross;
	cout <<" Initializing Input Stream !";
	cout <<" Game Ready ! "<< endl;
	matrixDisp();
	
	while (mark == false){
		mark = true;
		cout << "\n " << curChar << "'s Turn now !" << endl;
		cout <<"\n Enter the Index : ";
		cin >> num;
		
		system("cls");
		cout <<"\n\t\t MCUBE COMPUTING SYSTEMS \n\t\t Tic Tac Toe ";
		cout <<"\n Generating Index for Matrix !" << endl;
		
		checker(&num, &mark, &curChar);
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
		
		cout <<"\n Creating Matrix !  ";
		matrixGen();
		cout <<" Matrix Created !\n";
		
		MatrixInput();
		
		cout <<"\n Enter 'a' for new game \n Enter 'e' to exit : ";
		cin >> button; 
		if (button == 'a') continue;
		if (button == 'e') break;
	}
	
	return 0;
}
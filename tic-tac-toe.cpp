#include <bits/stdc++.h>

using namespace std;

char board[3][3];
bool turn = true;
char symbol = 'O';


void initialise_board() {

    for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                    board[i][j] = ' ';
            }
    }


}


void print_board(){

	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
	cout << "------------" << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
	cout << "------------" << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
}

void print_matrix(){

	cout << endl << "***MATRIX***" << endl;
	cout << " 1 | 2 | 3 " << endl;
	cout << "------------" << endl;
	cout << " 4 | 5 | 6 " << endl;
	cout << "------------" << endl;
	cout << " 7 | 8 | 9 " << endl;
}

bool check_symbol(int input) {

    if(input < 1 || input > 9) return false;

    int k = 0;

    for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {

                    k++;

                    if(k == input && board[i][j] != ' ') {
                            return false;
                    }

            }
    }

    return true;

}

void add_symbol(int input){

    int k = 0;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){

            k++;

			if(k == input) {
                    board[i][j] = symbol;
                    return;
			}


		}
	}
}


bool check(){

	if(board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol)
		return true;
	if(board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol)
		return true;
	if(board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol)
		return true;

	if(board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol)
		return true;
	if(board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol)
		return true;
	if(board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol)
		return true;


	if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
		return true;
	if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
		return true;

	return false;
}






int main(){

	bool won = false;


	initialise_board();

	for(int moves = 0 ; moves < 9; moves++){

        cout << endl;

		print_board();
		cout << endl << endl;

		print_matrix();

		cout << endl;

		if(turn) {
                cout << "Player 1 Turn (Symbol: O)" << endl;
		} else {
                cout << "Player 2 Turn (Symbol: X)" << endl << endl;
		}

		int input;

		cout << "Enter Input from Given Matrix: ";
		cin >> input;

		while(check_symbol(input) == false){
			cout << "Invalid Input. Please Re-Enter input: ";
			cin >> input;
		}

		if(turn) {
                symbol = 'O';
		} else {
                symbol = 'X';
		}



		add_symbol(input);

		won = check();

		if(won == true){

			print_board();

			if(turn) {
                cout<<endl<<"*** Player 1 with 'O' symbol Won ***";
			} else {
			    cout<<endl<<"*** Player 2 with 'X' symbol Won ***";
			}

			break;
		}

		if(moves == 8){

			print_board();

			cout<<endl<<"*** MATCH DRAW ***";
		}

		turn = !turn;
	}

	return 0;
}

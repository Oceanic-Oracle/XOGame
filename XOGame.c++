#include <iostream>
#include <algorithm>
#include <locale>

class Field {
private:

	int var;

	char fieldXO[5][5] = {
						 {'1' , '|' , '2' , '|' , '3'},
						 {'-' , '*' , '-' , '*' , '-'},
						 {'4' , '|' , '5' , '|' , '6'},
						 {'-' , '*' , '-' , '*' , '-'},
						 {'7' , '|' , '8' , '|' , '9'}
	};


	void move() {
				std::cin >> var;
		
				verification(var);
		}

		void verification(int x) {
			if (x < 1 || x > 9) {
				std::cout << "Ошибка, выбрана неверная клетка. Попробуйте еще раз." << std::endl;
				move();
			}
		}

		void replaceX(int x) {
			char sym = 'X';
			int symbol = '0' + var;

			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (fieldXO[i][j] == symbol) {
						fieldXO[i][j] = 'X';
						if (checkWin(sym)) {
							output_field();
							std::cout << "Крестики победили!!!";
							exit(0);
						}
						i = 5;
						j = 5;
					}
					else if (i == 4 && j == 4) {
						std::cout << "Клетка занята." << std::endl << std::endl;
						move_of_crosses();
					}
				}
			}
		}

		void replaceO(int x) {
			char sym = 'O';
			int symbol = '0' + var;

			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (fieldXO[i][j] == symbol) {
						fieldXO[i][j] = 'O';
						if (checkWin(sym)) {
							output_field();
							std::cout << "Нолики победили!!!";
							exit(0);
						}
						i = 5;
						j = 5;
					}
					else if (i == 4 && j == 4) {
						std::cout << "Клетка занята." << std::endl << std::endl;
						move_of_zeros();
					}
				}
			}
		}


		bool checkWin(char playerSymbol) {

			for (int i = 0; i < 5; i += 2) {
				if (fieldXO[i][0] == playerSymbol && fieldXO[i][2] == playerSymbol && fieldXO[i][4] == playerSymbol) {
					return true;
				}
			}


			for (int j = 0; j < 5; j += 2) {
				if (fieldXO[0][j] == playerSymbol && fieldXO[2][j] == playerSymbol && fieldXO[4][j] == playerSymbol) {
					return true;
				}
			}


			if ((fieldXO[0][0] == playerSymbol && fieldXO[2][2] == playerSymbol && fieldXO[4][4] == playerSymbol) ||
				(fieldXO[0][4] == playerSymbol && fieldXO[2][2] == playerSymbol && fieldXO[4][0] == playerSymbol)) {
				return true;
			}

			return false;
		}


public:

	void output_field() {
		std::cout << "Вот поле на данный момент: " << std::endl;
		for (int i = 0; i != 5; i++) {
			for (int j = 0; j != 5; j++) {
				std::cout << fieldXO[i][j] << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void move_of_crosses() {
		std::cout << "Кресты ходят на клетку:" << std::endl;

		move();

		replaceX(var);
	}

	void move_of_zeros() {
		std::cout << "Нули ходят на клетку:" << std::endl;

		move();

		replaceO(var);
	}
};


int main() {
	setlocale(LC_ALL, "Russian");

	Field XO;

	std::cout << "Игра крестики нолики." << std::endl << std::endl;

	int count = 0;
	while (true) {

		XO.output_field();

		XO.move_of_crosses();
		count++;

		if (count == 9) {
			break;
		}

		XO.output_field();

		XO.move_of_zeros();
		count++;
	}


	std::cout << "Ничья! Игра окончена.";

	return 0;
}
#include "stdafx.h"
#include <iostream>

using namespace std;

const int size_of_word = 5;

int number_of_attemps = 10;

char word[size_of_word];

char secret_word[size_of_word] = {'w','o','r','l','d'};

int quantity_of_letters;

int Bull = 0;

int Cow = 0;

void First_screen() {

	cout <<"          Welkome in Bulls & Cows geme";
	cout << "                                                 " << endl;
	cout << "             }   {        ___                    " << endl;
	cout << "        _____(0 0)       (0 0)______             " << endl;
	cout << "      /|BULL |\\ /         \\ /| COW  |\\        " << endl;
	cout << "     / |_____| 0           0 |______| \\         " << endl;
	cout << "    *  |     |               |      |  *         " << endl;
	cout << "       ^     ^               ^      ^            " << endl;

}

void Count_letters() {

	int i = 0;

	quantity_of_letters = 0;

	while (word[i] != 0) {

		quantity_of_letters++;
		i++;
	}

}

void get_word() {

	cout << "You heve : "<< number_of_attemps << " attemps \nprint your word : ";
	cin >> word; 
	Count_letters();

	if (quantity_of_letters != 5) {

		cout << "Eror you must enter 5 leter word" << endl;
		get_word();
		
	}

}

void Cow_and_Bull() {

	Cow = 0;

	Bull = 0;

	for (int i = 0; i < size_of_word; i++) {

		if (secret_word[i] == word[i]) {

			Bull++;

		}
		
	}

	for (int i = 0; i < size_of_word; i++) {

		for (int j = 0; j < size_of_word; j++) {

			if (i != j) {

				if (secret_word[j] == word[i]) {

					Cow++;

				}
			}

		}

	}

	cout << "Bull: " << Bull << " Cow: " << Cow << endl;

}

void Starting_the_game() {

	First_screen();

	int Magical_number = 0; // без этого числа вы будете всегда проигрывать

	while (number_of_attemps > 0) {

		get_word();
		Cow_and_Bull();
		number_of_attemps--;
		if (Bull == 5) {

			Victory();
			Magical_number = 1;

		}

	}

	if (Magical_number == 0) {

		Loss();

	}

}

int Play_again() {

	char answer;
	cout << "Do you want play again ?(Y/N)";
	cin >> answer;

	if (answer == 'Y' || answer == 'N') {

		if (answer == 'Y') {

			number_of_attemps = 10;
			Starting_the_game();
			
		}

		if (answer == 'N') {
			number_of_attemps = 0;
			return 0;

		}

	}
	else {

		cout << "Eror print 'Y' or 'N' ";
		Play_again();
	}
}

void Victory() {

	cout << "You win!!!" << endl;
	Play_again();

}

void Loss() {

	cout << "You loss ):" << endl;
	Play_again();

}

int main() {
	
	Starting_the_game();

}


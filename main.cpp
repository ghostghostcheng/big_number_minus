#include <iostream>
using namespace std;

int main() {
	char char1[100], char2[100];
	int num1[100], num2[100], result[101], bigger[100], smaller[100];
	int str_len_char1 = 0, str_len_char2 = 0;

	for (int i = 0; i < 100; i++) {
		char1[i] = -1;
		char2[i] = -1;
		num1[i] = -1;
		num2[i] = -1;
		bigger[i] = -1;
		smaller[i] = -1;
	}

	cout << "input num1 (less than 100 lenth):";
	cin.getline(char1, 100);
	str_len_char1 = strlen(char1);
	char1[str_len_char1] = -1;

	cout << "input num2 (less than 100 lenth):";
	cin.getline(char2, 100);
	str_len_char2 = strlen(char2);
	char2[str_len_char2] = -1;

	for (int i = 0; i < str_len_char1; i++) {     
		num1[i] = char1[str_len_char1 - i - 1] - 48;   //48 for ascii
		cout << num1[i];
	}

	cout << endl;

	for (int i = 0; i < str_len_char2; i++) {     
		num2[i] = char2[str_len_char2 - i - 1] - 48;   //48 for ascii
		cout << num2[i];
	}

	cout << endl;

	if (str_len_char1 > str_len_char2) {
		memcpy(bigger, num1, sizeof(num1));
		memcpy(smaller, num2, sizeof(num2));
	} else if (str_len_char2 > str_len_char1) {
		memcpy(bigger, num2, sizeof(num2));
		memcpy(smaller, num1, sizeof(num1));
	} else {
		if (num1[str_len_char1 - 1] > num2[str_len_char2 - 1]) {
			memcpy(bigger, num1, sizeof(num1));
			memcpy(smaller, num2, sizeof(num2));
		} else {
			memcpy(bigger, num2, sizeof(num2));
			memcpy(smaller, num1, sizeof(num1));
		}
	}

	int j = 0;
	int back = 0, tmp_result = 0;

	for (j; j < 100; j++) {
		
		if (bigger[j] < 0 && smaller[j] < 0) {
			break;
		} else {

			if (bigger[j] < 0) {
				bigger[j] = 0;
			}

			if (smaller[j] < 0) {
				smaller[j] = 0;
			}

			if (bigger[j] < smaller[j]) {
				back = 10;
				bigger[j + 1] = bigger[j + 1] - 1;
			} else {
				back = 0;
			}

			result[j] = (bigger[j] + back - smaller[j] );
		}
	}

	for (int i = j - 1; i >= 0; i--) {
		cout << result[i];
	}
	
	system("pause");
}


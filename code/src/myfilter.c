#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <malloc.h>

int filter(char** arr, int size, char** arr_filt) {
	int number = 0;
	char symbol_1, symbol_2;

	for (int i = 0; i < size; i++) {
		int len = (unsigned)strlen(arr[i]);
		if (len > 2) {
			symbol_1 = arr[i][0];
			int fl = 0;
			for (int j = 1; j < len; j++) {
				if ((arr[i][j] != symbol_1) && (fl == 0)) {
					fl = 1;
					symbol_2 = arr[i][j];
				} else if ((arr[i][j] != symbol_1) && (fl == 1) && (arr[i][j] != symbol_2)) {
					fl = 2;
					symbol_2 = arr[i][j];
					number++;
					j = len;
				}
			}
			if (fl == 2) {
				arr_filt[number - 1] = (char*)calloc(255, sizeof(char));
				strncpy(arr_filt[number - 1], arr[i], strlen(arr[i]));
			}
		}
	}
	return number;
}

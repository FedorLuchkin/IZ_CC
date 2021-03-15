#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "megafile.h"
#include "myfilter.h"
#include "myinput.h"

int main() {
	int  n = 0, k = 0, new_number = 0;
	char** mas, ** mas_filter;
	mas = (char**)calloc(1, sizeof(char*));
	mas = my_input(mas, &k, &n);
	mas_filter = (char**)calloc(k, sizeof(char*));
	new_number = filter(mas, k, mas_filter);
	clearing(mas, n, k, mas_filter, new_number);
	return 0;
}

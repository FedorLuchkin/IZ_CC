#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "megafile.h"
#include <string.h>
#include <stdlib.h>

char** my_input(char** arr, int *size, int *size_all) {
  int fl = 1, n = 1, k = 0;
  char str[255];
  arr[0] = (char*)calloc(255, sizeof(char));
  puts("Input strings(input 'END' to finish):");
  while (fl != 0) {
	  fgets(str, 255, stdin);
    	fl = strncmp(str, "END", 3);
    	if (fl != 0) {
			strncpy(arr[k], str, strlen(str) - 1);
    		k++;
			if ((fl != 0) && (n == k)) {
				n *= 2;
				arr = change_size(arr, n, k);
			}
		}
		*size = k;
		*size_all = n;
		}
	return arr;
}

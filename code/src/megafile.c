#include <stdio.h>
#include <string.h>
#include <malloc.h>

char** change_size(char** arr, int next, int pre) {
	char** arr2 = (char**)realloc(arr, next * sizeof(char*));

	for (int i = pre; i < next; i++) {
		arr2[i] = (char*)calloc(255, sizeof(char));
	}
	return arr2;
}

int clearing(char** arr, int size_arr, int size_input, char** arr_filter, int size_filt) {
	int i, j, len;

	puts("\nYour strings:");
	for (i = 0; i < size_input; i++) {
		len = (unsigned)strlen(arr[i]);
		for (j = 0; j < len; j++)
			printf("%c", arr[i][j]);
		if (size_arr > 1)
			printf("\n");
	}
	if (size_arr == 1)
		puts("NO STRINGS");

	puts("\nAfter filter:");
	if (size_filt == 0) {
		puts("NO STRINGS");
		free(arr_filter);
	} else {
		for (i = 0; i < size_filt; i++) {
			len = (unsigned)strlen(arr_filter[i]);
			for (j = 0; j < len; j++)
				printf("%c", arr_filter[i][j]);
			printf("\n");
		}
		for (j = 0; j < size_filt; j++) {
			free(arr_filter[j]);
		}
		free(arr_filter);
		arr_filter = NULL;
	}

	for (i = 0; i < size_arr - 1; i++) {
		free(arr[i]);
	}
	free(arr);
	arr = NULL;
	if (arr == arr_filter) {
		return 1;
	} else {
		return 0;
	}
}

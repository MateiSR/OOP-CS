#include <stdio.h>
#include <string.h>

int main() {

	char arr[256];	
	// https://cplusplus.com/reference/cstdio/scanf/ 
	// read 256 chars up to '\n', removing trailing spaces
	scanf(" %[^\n][256]", arr);
	printf("in arr: %s\n", arr);
	char words[128][256];
	unsigned int wordCnt = 0;
	char sep[] = " .";
	char* p = strtok(arr, sep);
	while (p) {
		printf("new word: %s\n", p);
		strcpy(words[wordCnt++], p);
		p = strtok(NULL, sep);
	}

	for (int i = 0; i < wordCnt - 1; i++)
		for (int j = i + 1; j < wordCnt; j++)
			if (strlen(words[i]) < strlen(words[j]) ||
				(strlen(words[i]) == strlen(words[j]) && strcmp(words[i], words[j]) < 0)) {
				char aux[256];
				strcpy(aux, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], aux);
			}
	
	printf("-------\n");
	for (int i = 0; i < wordCnt; i++) printf("%s\n", words[i]);


	return 0;
}
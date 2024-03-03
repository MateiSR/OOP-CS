#include <stdio.h>
#include <string.h>

unsigned long long convertCharArray(char* arr) {
	unsigned long long p = 1, retValue = 0;
	for (int i = strlen(arr) - 1; i >= 0; i--) {
		if (arr[i] == '\n') continue;
		retValue += (arr[i] - '0') * p;
		p *= 10;
	}
	printf("in arr: %s, out num: %d\n", arr, retValue);
	return retValue;
}

int main() {
	FILE* inputStream = fopen("in.txt", "r");
	if (!inputStream) {
		printf("Invalid input file\n");
		return -1;
	}
	char line[256];
	unsigned long long sum = 0;
	while (fgets(line, 256, inputStream)) {
		sum += convertCharArray(line);
	}

	printf("sum=%d\n", sum);

	return 0;
}
#include <stdio.h>

void printShortIntInBinary(int x) {
	for (int i = 8 * sizeof(int) - 1; i >= 0; i--) {
		printf("%d", (x >> i) & 1);
	}
	printf("\n");
}

int main() {
	int x = -2;
	printShortIntInBinary(x);
	return 0;
}
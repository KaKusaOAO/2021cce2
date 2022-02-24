#include <cstdio>
#include <cstring>

int main() {
	int sum = 0;
	char buffer[64];

	while(scanf("%s", buffer) != -1) {
		int count = 0;
		for(int i=0; i<strlen(buffer); i++) {
			if(buffer[i] == '2') count++;
		}
		printf("%d\n", count);
		sum += count;
	}

	printf("Total: %d\n", sum);
}

#include <cstdio>
#include <cstring>

int main() {
	char buffer[64];

	for(int j=0; j<4; j++) {
        scanf("%s", buffer);
		int count = 0;
		for(int i=0; i<strlen(buffer); i++) {
			if(buffer[i] == '2') count++;
		}
		printf("%d\n", count);
	}
}

#include <cstdio>

int main() {
    char buffer[2000];
    printf("Input some characters: ");
    scanf("%s", buffer);

    for(int i=0; i<2000; i++) {
        if(buffer[i] == '2') printf("Found 2!\n");
    }

    return 0;
}

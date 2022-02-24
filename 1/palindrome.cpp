#include <cstdio>
#define LEN 2048

int strlen(char *buffer) {
    char *ptr = buffer;
    while(1) {
        if(*(ptr++) == 0) {
            return ptr - buffer - 1;
        }
    }
}

bool isPalindrome(char *buffer) {
    int len = strlen(buffer);
    for(int a=0; a<(len+1)/2; a++) {
        int b = len - 1 - a;
        if(buffer[a] != buffer[b]) return false;
    }
    return true;
}

char aMap[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char nMap[] = "123456789";
char mirAMap[] = "A---3--HIL-JM-O---2TUVWXY5";
char mirNMap[] = "1SE-Z--8-";

bool isValidChar(char c) {
    if(c == '0') return false;
    if(c >= '1' && c <= '9') return true;
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}

char findMirror(char c) {
    if(!isValidChar(c)) return 0;
    if(c >= 'A' && c <= 'Z') {
        return mirAMap[c - 'A'];
    }
    if(c >= '1' && c <= '9') {
        return mirNMap[c - '1'];
    }
    return c;
}

bool isMirror(char *buffer) {
    int len = strlen(buffer);
    for(int a=0; a<(len+1)/2; a++) {
        int b = len - 1 - a;
        if(!isValidChar(buffer[a])) return false;
        if(buffer[a] != findMirror(buffer[b])) return false;
    }
    return true;
}

void handleInput(char *buffer) {
    printf("%s", buffer);
    bool p = isPalindrome(buffer);
    bool m = isMirror(buffer);

    if(p && m) {
        printf(" -- is a mirrored palindrome.\n");
    } else if(p) {
        printf(" -- is a regular palindrome.\n");
    } else if(m) {
        printf(" -- is a mirrored string.\n");
    } else {
        printf(" -- is not a palindrome.\n");
    }
}

void doTest() {
    handleInput("NOTAPALINDROME");
    handleInput("ISAPALINILAPASI");
    handleInput("2A3MEAS");
    handleInput("ATOYOTA");
}

int main() {
    // doTest();

    char buffer[LEN];
    while(scanf("%s", buffer) >= 1) {
        handleInput(buffer);
    }
}

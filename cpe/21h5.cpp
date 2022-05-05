#include <stdio.h>
#include <stdlib.h>

int offsetByChar(char c) {
    if (c == 'R') return 1;
    if (c == 'F') return -1;
    return 0;
}

void doCase(int n) {
    char data[51];
    scanf("%s", data);
    
    // 1. Calculate the height of the graph
    int y = 0, h = 0, offset = 0, len = 0;
    char prev = 'C'; // "R"ise, "F"all, "C"onstant
    for (int i=0; data[i]; i++, len++) {
        char c = data[i];
        if (prev == c) {
            y += offsetByChar(c);
        } else {
            if (c == 'C' && prev == 'R') y++;
            if (c == 'F' && prev == 'C') y--;
            prev = c;
        }
        
        if (offset > y) offset = y;
        if (h < y) h = y;
    }
    
    if (offset > 0) offset = 0;
    if (offset < 0) h += -offset;
    h++;
    
    // 2. Build a map and store data
    //    Index is based on (len * y) + x
    char *map = malloc(h * len);
    memset(map, ' ', h * len);
    
    y = 0;
    prev = 'C';
    for (int i=0; data[i]; i++) {
        char c = data[i];
        if (prev == c) {
            y += offsetByChar(c);
        } else {
            if (c == 'C' && prev == 'R') y++;
            if (c == 'F' && prev == 'C') y--;
            prev = c;
        }
        
        char symb = '_';
        switch(c) {
            case 'R':
                symb = '/';
                break;
            case 'F':
                symb = '\\';
                break;
        }
        map[len * (y-offset) + i] = symb;
    }
    
    printf("Case #%d:\n", n);
    
    // 3. Print the graph
     for (int i=0; i<h; i++) {
        for (int j=len-1; map[len * (h-i-1) + j] == ' '; j--) {
            map[len * (h-i-1) + j] = 0;
        }
    }
    
    for (int i=0; i<h; i++) {
        printf("| ");
        for (int j=0; map[len * (h-i-1) + j] != 0 && j < len; j++) {
            printf("%c", map[len * (h-i-1) + j]);
        }
        printf("\n");
    }
    printf("+");
    for (int i=0; i<len+2; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        doCase(i+1);
    }
}

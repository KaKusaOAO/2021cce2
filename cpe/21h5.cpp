#include <stdio.h>
#include <stdlib.h>

int offsetByChar(char c) {
    if (c == 'R') return 1;
    if (c == 'F') return -1;
    return 0;
}

void calcOrPlot(char *data, int *pH, int *pOffset, int *pLen, char *map) {
    int y = 0, h = 0, offset = 0, len = 0;
    if (pH) h = *pH;
    if (pOffset) offset = *pOffset;
    if (pLen) len = *pLen;
    
    char prev = 'C'; // "R"ise, "F"all, "C"onstant
    for (int i=0; data[i]; i++) {
        char c = data[i];
        if (prev == c) {
            y += offsetByChar(c);
        } else {
            if (c == 'C' && prev == 'R') y++;
            if (c == 'F' && prev == 'C') y--;
            prev = c;
        }
        
        if (map) {
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
        } else {
            if (offset > y) offset = y;
            if (h < y) h = y;
            len++;
        }
    }
    
    if (!map) {
        if (offset > 0) offset = 0;
        if (offset < 0) h += -offset;
        h++;
    
        if (pH) *pH = h;
        if (pOffset) *pOffset = offset;
        if (pLen) *pLen = len;
    }
}

void doCase(int n) {
    char data[51];
    scanf("%s", data);
    
    // 1. Calculate the height of the graph
    int h = 0, offset = 0, len = 0;
    calcOrPlot(data, &h, &offset, &len, 0);
    
    // 2. Build a map and store data
    char *map = malloc(h * len);
    memset(map, ' ', h * len);
    calcOrPlot(data, &h, &offset, &len, map);
    
    printf("Case #%d:\n", n);
    
    // 3. Write 0s to trim every line
    for (int i=0; i<h; i++) {
        for (int j=len-1; map[len * (h-i-1) + j] == ' '; j--) {
            map[len * (h-i-1) + j] = 0;
        }
    }
    
    // 4. Print the graph
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
    printf("\n\n");
    
    free(map);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        doCase(i+1);
    }
}

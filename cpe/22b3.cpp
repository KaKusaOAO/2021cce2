#include <cstdio>

unsigned char color(char c) {
    switch(c) { // CMYK
        case 'M': return 0b0100;
        case 'Y': return 0b0010;
        case 'C': return 0b1000;
        case 'R': return 0b0110;
        case 'B': return 0b1111;
        case 'G': return 0b1010;
        case 'V': return 0b1100;
        case 'W': return 0;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i=0; i<n; i++) {
        int m, y, c;
        scanf("%d %d %d", &m, &y, &c);
        
        bool isOut = false;
        char line[100000];
        scanf("%s", line);
        for (int j=0; line[j]!=0; j++) {
            unsigned char f = color(line[j]);
            if (f & 0b0100) m--;
            if (f & 0b0010) y--;
            if (f & 0b1000) c--;
            
            if (c<0 || m<0 || y<0) {
                printf("NO\n");
                isOut = true;
                break;
            }
        }
        
        if(!isOut) {
            printf("YES %d %d %d\n", m, y, c);
        }
    }
}
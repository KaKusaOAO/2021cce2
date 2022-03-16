#include <cstdio>
#include <cstring>
#include <cstdlib>
#define LEN 2048

typedef struct {
    char code;
    int count;
} Entry;

Entry entries[256];

int compareEntries(const void *a, const void *b) {
    if (a == 0) return -1;
    if (b == 0) return 1;

    Entry *aEntry = (Entry*)a;
    Entry *bEntry = (Entry*)b;

    int deltaCount = aEntry->count - bEntry->count;
    return deltaCount == 0 ? bEntry->code - aEntry->code : deltaCount;
}

int handleInput(char *line) {
    // Initialize
    for (int i=0; i<256; i++) {
        entries[i] = { (char)i, 0 };    
    }

    // Analyze input
    int len = strlen(line);
    for (int i=0; i<len; i++) {
        char c = line[i];
        entries[c].count++;
    }

    // Sort entries and output
    qsort(entries, 256, sizeof(Entry), compareEntries);
    for (int i=0; i<256; i++) {
        Entry entry = entries[i];
        if (entry.count == 0) continue;
        printf("%d %d\n", entry.code, entry.count);
    }
    printf("\n");
}

void doTest() {
    handleInput("AAABBC");
    handleInput("122333444555");
}

int main() {
    // doTest();

    char buffer[LEN];
    while(gets(buffer)) {
        handleInput(buffer);
    }
}
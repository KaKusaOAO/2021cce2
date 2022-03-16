#include <cstdio>
#include <cstring>
#include <cstdlib>

//: The "-Wwrite-strings" warning is annoying
#define K_USE_CPP_STRING
#define LEN 2048

#ifdef K_USE_CPP_STRING
#include <string>
#endif // K_USE_CPP_STRING

#if defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 192929917
//: Visual Studio 2015 removes gets() support
#define K_GETS_MAX_VER 0L
#else  // defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 192929917
//: C++11 removes gets() support
#define K_GETS_MAX_VER 201103L
#endif // defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 192929917

#if __cplusplus >= K_GETS_MAX_VER
#define KGetS gets_s
#else // __cplusplus >= K_GETS_MAX_VER
#define KGetS(x, len) gets(x)
#endif // __cplusplus >= K_GETS_MAX_VER

#ifdef K_USE_CPP_STRING
typedef std::string KString;
#else  // K_USE_CPP_STRING
typedef char* KString;
#endif // K_USE_CPP_STRING

inline int KStrLen(KString str) {
#ifdef K_USE_CPP_STRING
    return str.length();
#else  // K_USE_CPP_STRING
    return strlen(str);
#endif // K_USE_CPP_STRING
}

typedef struct {
    char code;
    int count;
} Entry;

Entry entries[256];
int caseCount = 0;

int compareEntries(const void *a, const void *b) {
    if (a == 0) return -1;
    if (b == 0) return 1;

    Entry *aEntry = (Entry*)a;
    Entry *bEntry = (Entry*)b;

    int deltaCount = aEntry->count - bEntry->count;
    return deltaCount == 0 ? bEntry->code - aEntry->code : deltaCount;
}

int handleInput(KString line) {
    // Initialize
    for (int i=0; i<256; i++) {
        Entry entry;
        entry.code = (char)i;
        entry.count = 0;
        entries[i] = entry;    
    }

    // Analyze input
    int len = KStrLen(line);
    for (int i=0; i<len; i++) {
        char c = line[i];
        entries[c].count++;
    }

    // Sort entries and output
    qsort(entries, 256, sizeof(Entry), compareEntries);
    if (caseCount > 0) printf("\n");
    for (int i=0; i<256; i++) {
        Entry entry = entries[i];
        if (entry.count == 0) continue;
        printf("%d %d\n", entry.code, entry.count);
    }
    caseCount++;
}

void doTest() {
    handleInput("AAABBC");
    handleInput("122333444555");
}

int main() {
    // doTest();

    char buffer[LEN];
    while(KGetS(buffer, LEN)) {
        handleInput(buffer);
    }
}
#include <cstdio>
#include <cstring>
#include <cstdlib>

//: The "-Wwrite-strings" warning is annoying
#define K_USE_CPP_STRING
#define LEN 2048

#ifdef K_USE_CPP_STRING
#include <string>
#endif // K_USE_CPP_STRING

//: gets() is unsafe so we are using alternatives.
inline char *KGetS(char *buffer, int len) {
#if (defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 192929917)
    // gets_s seems like a Windows only method
    return gets_s(buffer, len);
#else // (defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 192929917)
    // Calling gets() on some OS generates a warning at runtime, so we need to use fgets() instead.
    // fgets() contains a newline char at the end, we need to remove that.
    char *result = fgets(buffer, len, stdin);
    int l = strlen(buffer);
    buffer[l-1] = '\0';
    return result;
#endif // (defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 192929917)
}

template<int size>
inline char *KGetS(char (&buffer)[size]) {
    return KGetS(buffer, size);
}

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

inline const char *KCStr(KString str) {
#ifdef K_USE_CPP_STRING
    return str.c_str();
#else  // K_USE_CPP_STRING
    return str;
#endif // K_USE_CPP_STRING
}

int caseCount = 0;

void handleInput(KString line) {
    // Initialize
    char entries[256] = {};

    // Analyze input
    int len = KStrLen(line);
    for (int i=0; i<len; i++) {
        char c = line[i];
        entries[c]++;
    }

    for (int f=1; f<=len; f++) {
        // Loop through all possible frequency of the characters in ascending order.
        // The max possible frequency if the length of the line.
        for (int c=128; c>=32; c--) {
            // Loop for every possible ASCII input characters in descending order.
            // If the frequency matches the count of the character, print it out.
            if(entries[c] == f) {
                printf("%d %d\n", c, entries[c]);
            }
        }
    }
    caseCount++;
}

void doTest() {
    handleInput("AAABBC");
    handleInput("122333444555");
}

int main(){
    // doTest();

    char buffer[LEN];
    while(KGetS(buffer)) {
        handleInput(buffer);
    }
}
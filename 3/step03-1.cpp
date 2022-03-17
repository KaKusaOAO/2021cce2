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
    // A trick to prevent -Wreturn-stack-address warning.
    // (warning: address of stack memory associated with parameter 'str' returned)
    const char* result = str.c_str();
    return result;
#else  // K_USE_CPP_STRING
    return str;
#endif // K_USE_CPP_STRING
}

int handleInput(KString line) {
    printf("%s\n", KCStr(line));
}

void doTest() {
    handleInput("AAABBC");
    handleInput("122333444555");
}

int main() {
    // doTest();

    char buffer[LEN];
    while(KGetS(buffer)) {
        handleInput(buffer);
    }
}
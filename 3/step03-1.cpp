#include <cstdio>
#include <cstring>
#include <cstdlib>

//: The "-Wwrite-strings" warning is annoying
#define K_USE_CPP_STRING
#define LEN 2048

#ifdef K_USE_CPP_STRING
#include <string>
#endif // K_USE_CPP_STRING

//: Visual Studio 2015 & C++11 removes gets() support (and there's no gets_s before that)
inline char *KGetS(char *buffer, int len) {
#if (defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 192929917) || __cplusplus >= 201103L
    return gets_s(buffer, len);
#else // (defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 192929917) || __cplusplus >= 201103L
    return gets(buffer);
#endif // (defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 192929917) || __cplusplus >= 201103L
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
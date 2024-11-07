#include <stdio.h>

int main() {
#ifdef _MSC_VER
    printf("Compiler: Microsoft Visual C++\n");
#else
    printf("Unknown compiler (not Microsoft Visual C++)\n");
#endif

#ifdef __STDC__
    printf("ISO C standard is supported\n");
#else
    printf("ISO C standard is not supported\n");
#endif

#ifdef __GNUC__
    printf("Compiler: GCC\n");
#endif

#ifdef __clang__
    printf("Compiler: Clang\n");
#endif

#if defined(_WIN32) || defined(_WIN64)
    printf("Operating system: Windows\n");
#elif defined(__linux__)
    printf("Operating system: Linux\n");
#elif defined(__APPLE__)
    printf("Operating system: macOS\n");
#else
    printf("Unknown operating system\n");
#endif

    return 0;
}

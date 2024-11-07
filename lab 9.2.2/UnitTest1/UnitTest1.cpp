#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <sstream>
#include <cstdarg>
#include "../lab 9.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Mock the printf function to capture output
std::stringstream test_output;
extern "C" int test_printf(const char* format, ...) {
    char buffer[256];
    va_list args;
    va_start(args, format);
    vsprintf_s(buffer, format, args);
    va_end(args);
    test_output << buffer;
    return 0;
}

// Macro to redirect printf to our test version
#define printf test_printf

namespace UnitTest1 {
    TEST_CLASS(CompilerOSDetectionTests) {
public:
    TEST_METHOD_INITIALIZE(SetUp) {
        test_output.str("");  // Clear the output buffer before each test
        test_output.clear();
    }

    TEST_METHOD(TestCompilerDetection) {
        // Run the detection code
        main();
        std::string output = test_output.str();

        // Check compiler detection
#ifdef _MSC_VER
        Assert::IsTrue(output.find("Compiler: Microsoft Visual C++") != std::string::npos);
#else
        Assert::IsTrue(output.find("Unknown compiler (not Microsoft Visual C++)") != std::string::npos);
#endif

#ifdef __STDC__
        Assert::IsTrue(output.find("ISO C standard is supported") != std::string::npos);
#else
        Assert::IsTrue(output.find("ISO C standard is not supported") != std::string::npos);
#endif

#ifdef __GNUC__
        Assert::IsTrue(output.find("Compiler: GCC") != std::string::npos);
#endif

#ifdef __clang__
        Assert::IsTrue(output.find("Compiler: Clang") != std::string::npos);
#endif
    }
    };
}
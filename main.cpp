#include "LCS.h"

int main() {
    std::string A = "This is some text";
    std::string B = "Here is text too";
    std::string result = LCS_Diffing(A, B);
    std::cout << "Result: \n" << result << std::endl;
    return 0;
}

#include "LCS.h"

int main() {
    string A = "This is some text";
    string B = "Here is text too";
    string result = LCS(A, B);
    //std::string result = LCS_Diffing(A, B);
    cout << "Testing the LCS: \n\n";
    cout << "Result: \n" << "|" << result << "|" << '\n';
    cout << "\nthe \"|\" indicators mark the beginning and the end of the LCS (make spaces visible)\n";

    cout << "\nTesting the LCS_Diffing\n\n";
    LCS_Diffing("TestFile1.txt", "TestFile2.txt");
    return 0;
}

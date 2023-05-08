#include "LCS.h"

int main() {
    string A = "This is some text";
    string B = "Here is text too";
    string result = LCS(A, B);
    int reduced_result = Reduced_memory_LCS_length(A, B);
    int minimal_result = Minimal_memory_LCS_length(A, B);
    //string result = LCS_Diffing(A, B);
    cout << "Testing the LCS: \n\n";
    cout << "Result: \n" << "|" << result << "|" << '\n';
    cout << "\nthe \"|\" indicators mark the beginning and the end of the LCS (makes spaces visible)\n";

    cout << "\nTesting the Reduced Memory LCS to calculate lenght O( 2*min(m,n) )\n";
    cout << reduced_result << '\n';

    cout << "\nTesting the Minimal Memory LCS to calculate lenght O( min(m,n ) )\n";
    cout << minimal_result << '\n';

    cout << "\nTesting the LCS_Diffing\n\n";
    LCS_Diffing("TestFile1.txt", "TestFile2.txt");
    return 0;
}

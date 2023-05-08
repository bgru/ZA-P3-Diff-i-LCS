#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int Minimal_memory_LCS_length(const string& A, const string& B) {
    size_t m = A.size();
    size_t n = B.size();

    if (n > m) {
        return Minimal_memory_LCS_length(B, A); // Swap A and B to ensure that A is the smaller string
    }

    vector<int> dp(n + 1, 0);
    int prev_diag = 0;

    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            int temp = dp[j]; // Store the current value of dp[j] before updating it
            if (A[i - 1] == B[j - 1]) {
                dp[j] = prev_diag + 1;
            }
            else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev_diag = temp; // Update prev_diag for the next iteration
        }
        prev_diag = 0; // Reset prev_diag for the next row
    }

    return dp[n];
}

int Reduced_memory_LCS_length(const string& A, const string& B) {
    size_t m = A.size();
    size_t n = B.size();

    if (n > m) {
        return Reduced_memory_LCS_length(B, A); // Swap A and B to ensure that A is the smaller string
    }

    vector<vector<int>> dp(2, vector<int>(n + 1, 0));

    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            }
            else {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
    }

    return dp[m % 2][n];
}

// Function to find the longest common subsequence of two strings
string LCS(const string& A, const string& B) {
    size_t m = A.size();
    size_t n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs = "";
    size_t i = m, j = n;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs = A[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return lcs;
}

// Function to implement file diffing using the longest common subsequence
void LCS_Diffing(const string& file1, const string& file2) {
    ifstream inFile1(file1);
    ifstream inFile2(file2);

    if (!inFile1.is_open() || !inFile2.is_open()) {
        cerr << "Error opening one of the files" << endl;
        return;
    }

    string line1, line2;
    while (getline(inFile1, line1) && getline(inFile2, line2)) {
        string lcs = LCS(line1, line2);

        if (lcs == line1 && lcs == line2) {
            cout << "= " << line1 << endl;
        }
        else {
            cout << "- " << line1 << endl;
            cout << "+ " << line2 << endl;
        }
    }

    // Handle any remaining lines in either file
    while (getline(inFile1, line1)) {
        cout << "- " << line1 << endl;
    }
    while (getline(inFile2, line2)) {
        cout << "+ " << line2 << endl;
    }

    inFile1.close();
    inFile2.close();
}

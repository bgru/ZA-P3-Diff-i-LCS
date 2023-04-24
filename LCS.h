#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the longest common subsequence of two strings
std::string LCS(const std::string& A, const std::string& B) {
    int m = A.size();
    int n = B.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::string lcs = "";
    int i = m, j = n;
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

// Function to implement diffing using the longest common subsequence
std::string LCS_Diffing(const std::string& A, const std::string& B) {
    std::string lcs = LCS(A, B);
    std::string resultA = "";
    std::string resultB = "";

    int i = 0, j = 0, k = 0;
    while (k < lcs.size()) {
        bool addedPlus = false;
        bool addedMinus = false;
        while (i < A.size() && A[i] != lcs[k]) {
            if (!addedPlus) {
                resultA += "+";
                addedPlus = true;
            }
            resultA += A[i];
            i++;
        }
        addedPlus = false;
        while (j < B.size() && B[j] != lcs[k]) {
            if (!addedMinus) {
                resultB += "-";
                addedMinus = true;
            }
            resultB += B[j];
            j++;
        }
        addedMinus = false;

        resultA += "=";
        resultA += lcs[k];
        resultB += "=";
        resultB += lcs[k];

        i++;
        j++;
        k++;
    }

    // No, these loops are not necessary as the logic above handles the entire strings
    // Keeping them here will lead to repeating the last character in each string

    return resultA + "\n" + resultB;
}

#include <stdio.h>
#include <string.h>

#define MAX_LEN 40

int dp[MAX_LEN][MAX_LEN];

int max(int a, int b) { // check max
  return a > b ? a : b;
}

int lcs(char *M, char *N, int i, int j) {
  if (i < 0 || j < 0) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (M[i] == N[j]) {
    dp[i][j] = 1 + lcs(M, N, i - 1, j - 1); // recurrsion
  } else {
    dp[i][j] = max(lcs(M, N, i - 1, j), lcs(M, N, i, j - 1));
  }
  return dp[i][j];
}

int main() {
  char a[MAX_LEN], b[MAX_LEN];
  scanf("%s%s", a, b);
  int m = strlen(a), n = strlen(b);

  // Initialize dp initialization array
  memset(dp, -1, sizeof(dp));

  printf("%d\n", lcs(a, b, m - 1, n - 1));

  // Construct LCS for printing lcs
  int i = m - 1, j = n - 1, k = dp[i][j] - 1;
  char lcs[MAX_LEN];
  while (i >= 0 && j >= 0) {
    if (a[i] == b[j]) {
      lcs[k--] = a[i];
      i--;
      j--;
    } else if (dp[i][j - 1] > dp[i - 1][j]) {
      j--;
    } else {
      i--;
    }
  }
  // Print LCS
  printf("%s\n", lcs);

  return 0;
}
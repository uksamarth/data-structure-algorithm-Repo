#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_COINS 100
#define MAX_SUM 10000

void coinChange(int coins[], int n, int sum) {
    int i, j;
    int dp[MAX_SUM];
    int prev[MAX_SUM];
    int minCoins[MAX_SUM];

    for (i = 0; i <= sum; i++) {
        dp[i] = INT_MAX;
        prev[i] = -1;
        minCoins[i] = 0;
    }
    dp[0] = 0;

    for (i = 0; i < n; i++) {
        for (j = coins[i]; j <= sum; j++) {
            if (dp[j - coins[i]] != INT_MAX && dp[j - coins[i]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i]] + 1;
                prev[j] = j - coins[i];
                minCoins[j] = coins[i];
            }
        }
    }

    if (dp[sum] == INT_MAX) {
        printf("No solution found.\n");
    } else {
        printf("Minimum number of coins required: %d\n", dp[sum]);
        printf("Coins used: ");
        int x = sum;
        while (x != 0) {
            printf("%d ", minCoins[x]);
            x = prev[x];
        }
        printf("\n");
    }
}

int main() {
    int n, i, coins[MAX_COINS], sum;

    printf("Enter the number of coins: ");
    scanf("%d", &n);
    printf("Enter the values of coins: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &sum);

    coinChange(coins, n, sum);

    return 0;
}

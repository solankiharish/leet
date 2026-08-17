
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Prefix sums for quick subarray sum calculation
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // Helper to get sum of subarray [l, r]
        auto getSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };

        // dp[i][j] storing maximum score for subarray stoneValue[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Iterate over length of the subarray
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;

                for (int k = i; k < j; ++k) {
                    int leftSum = getSum(i, k);
                    int rightSum = getSum(k + 1, j);

                    if (leftSum < rightSum) {
                        dp[i][j] = max(dp[i][j], leftSum + dp[i][k]);
                    } else if (leftSum > rightSum) {
                        dp[i][j] = max(dp[i][j], rightSum + dp[k + 1][j]);
                    } else { // leftSum == rightSum
                        dp[i][j] = max(dp[i][j], leftSum + max(dp[i][k], dp[k + 1][j]));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
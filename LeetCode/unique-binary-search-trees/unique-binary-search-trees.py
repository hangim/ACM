class Solution:
    # @return an integer
    def numTrees(self, n):
        dp = {0 : 0, 1 : 1, 2: 2}
        for i in range(3, n + 1):
            dp[i] = 2 * dp[i-1]
            for j in range(1, i - 1):
                dp[i] += dp[j] * dp[i-1-j]
        return dp[n]

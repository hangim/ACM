class Solution:
    # @param prices, a list of intege
    # @return an integer
    def maxProfit(self, prices):
        if len(prices) < 2:
            return 0

        ans = 0
        last = prices[0]
        for i in prices:
            if i > last:
                ans += i - last
            last = i
        return ans

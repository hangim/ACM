class Solution:
    # @return an intege
    def reverse(self, x):
        if x < 0:
            return int(str(x)[:0:-1]) * -1
        else:
            return int(str(x)[::-1])


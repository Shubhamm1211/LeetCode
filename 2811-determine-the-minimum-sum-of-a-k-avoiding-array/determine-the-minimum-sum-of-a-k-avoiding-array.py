class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        numSet = set()
        i = 1
        while len(numSet) != n:
            if k - i not in numSet:
                numSet.add(i)
            i += 1
        return sum(numSet)
        
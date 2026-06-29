class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        count = 0
        for str in patterns :
            if str in word: count += 1
        return count
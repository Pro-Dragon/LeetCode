class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        Gratio = 0.08333333333333333333333333333333 * minutes
        if hour == 12 : hour = 0
        rem = abs((hour * 5 + Gratio) - minutes) * 6.0
        return min(rem, 360 - rem)
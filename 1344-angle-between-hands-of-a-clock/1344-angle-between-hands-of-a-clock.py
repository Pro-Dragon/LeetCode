class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        if hour == 12 and minutes == 0 :
            return 0 
        Gratio = 0.08333333333333333333333333333333 * minutes
        if hour == 12 :
            hour = 0
        rem = hour * 5 + Gratio
        rem = abs(rem - minutes) * 6.0
        print(rem)
        if rem < 180 :
            return rem        
        return 360 - rem
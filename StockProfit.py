# 121. Best time to buy and sell stock
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l, r = 0, 1
        Pmax = 0
        while(r<len(prices)):
            if prices[l]<prices[r]:
                p = prices[r]-prices[l]
                Pmax = max(Pmax, p)
            else:
                l = r
            r+=1
           
        return Pmax

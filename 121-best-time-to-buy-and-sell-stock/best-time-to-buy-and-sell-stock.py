class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        #want to buy at the lowest price and sell at the larget price following that lowest price
        #track best range so far and then also the min element
        max_profit = -1
        min_price = float('inf')
        for p in prices:
            min_price = min(min_price, p)
            max_profit = max(max_profit, p - min_price)
        return max_profit
        
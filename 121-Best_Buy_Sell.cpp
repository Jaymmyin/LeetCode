class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0){return 0;}
        int maxP = 0;
        int minP = prices[0];
        
        //从右向左做减法，
        for(int i = 1; i < prices.size(); i++)
        {
            minP = min(minP, prices[i]);
            maxP = max(maxP, prices[i] - minP);
        }
        
        return maxP;
    }
};
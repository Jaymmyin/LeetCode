class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, sum = 0, i = 0;
        int count = 0;
        
        if (prices.size() == 0){return 0;}//如果输入是{}，则返回0；这一点是不能忽略的
        while (i < prices.size() - 1)
        {
            count = 0;
            while(prices[i+1] - prices[i] > 0)
            {
                if(i+1 == prices.size() - 1) //针对最后一个数是比前面至少有一个数大的情况，这个是要把它计算在内
                {
                    count++;
                    i++;
                    break;
                }
                count++;//count的引入，旨在记录股票买入的时间，用买的时间点价格减去count的次数，得到股票买入时的价格
                i++;
            }
        
            if (i >= 1)
            {
                sum = prices[i] - prices[i-count];
            }else
            {
                sum = 0;
            }
            i++;
            sum = max(0, sum);
            maxProfit = maxProfit + sum;
        }
        
        return maxProfit;
    }
};
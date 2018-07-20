class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        //动态规划类题目，主要是理解比较难
        vector<int> dp(cost.size()+1, 0); 
        //第i个阶梯要么是从第i-1个阶梯跳一级上来的，要么是从第i-2个阶梯跳两级上来的
        for(int i=2; i<dp.size(); i++)
        {
            dp[i] = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
        }
        
        return dp[cost.size()];
    }
};
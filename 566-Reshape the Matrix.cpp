class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        std::vector<vector<int>> reShape(r);//这里声明二维数组时，接着要申请二维数组大小
        for(int i=0; i<r; i++)reShape[i].resize(c);//同样，这里也要初始化大小
        int row=0, row1=0;
        int col=0, col1=0;
        //维护一个最大值等于row*col的变量
        int sum = 0;
        row = nums.size();
        col = nums[0].size();
        if(row*col != r*c)
        {
            return nums;
        }else
        {
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                {
                    row1 = sum/col; //这里和下面都是col，不是row
                    col1 = sum%col;
                    reShape[i][j] = nums[row1][col1];
                    sum++;
                }
            }
            return reShape;
        }
    }
};
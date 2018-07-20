class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        if(row == 1 || col == 1)return true;
        
        //方法一：两两比较
        
        //方法二：根据观察，后一行去掉首位和前一行去掉末位需要相等
        
        for(int i=0; i<row-1; i++)
        {
            int j=0;
            while(j<col-1)
            {
                if(matrix[i][j] != matrix[i+1][j+1])
                {
                    return false;
                }
                j++;
            }
        }
        return true;
    }
};
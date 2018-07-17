class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxIsland = 0;
        int tempIsland;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    //grid[i][j] = 0;
                    //tempIsland = 1;
                    maxIsland = max(maxIsland, curSearch(grid, i, j));//深度优先搜索
                    //递归就是先把通式写好，先找好递归的关系式，后面的再慢慢写
                }
                
            }
        }
        
        return maxIsland;
    }
    
private:
    int curSearch(vector<vector<int>>& curGrid, int x, int y)
    {
        curGrid[x][y] = 0;//如果递归表示该处值不为0，所以要置零
        int tempIsland = 1;
        //这两个数组用向四周发散去找可行的island
        int ax[4] = {-1, 1, 0, 0};
        int by[4] = {0, 0, 1, -1};
        
        for(int i=0; i<4; i++)
        {
           int tx = x + ax[i]; //刚开始我这里写x = x + ax[i]，这在循环时是不对的。
           int ty = y + by[i];
            if(tx<0 || tx>=curGrid.size() || ty<0 || ty>=curGrid[0].size() || curGrid[tx][ty] == 0) continue;
            tempIsland = tempIsland + curSearch(curGrid, tx, ty);
        }
            
        return tempIsland;
    }
};
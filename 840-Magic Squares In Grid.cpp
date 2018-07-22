class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        if(grid.size()<=2 || grid[0].size()<=2)
            return 0;
        std::set<int> distinct;
        int sum = 0, count = 0;
        
        for(int i=0; i<grid.size()-2; i++)
        {
            for(int j=0; j<grid[i].size()-2; j++)
            {            
                if(grid[i+1][j+1] != 5)continue;
                
                sum = 0;
                for(int p=0; p<=2; p++)
                {
                    sum += grid[i][j+p];
                }
                if(sum != 15)continue;
                
                sum = 0;
                for(int p=0; p<=2; p++)
                {
                    sum += grid[i+1][j+p];
                }
                if(sum != 15)continue;
                
                sum = 0;
                for(int p=0; p<=2; p++)
                {
                    sum += grid[i+2][j+p];
                }
                if(sum != 15)continue;
                                
                sum = 0;
                for(int p=0; p<=2; p++)
                {
                    sum += grid[i+p][j];
                }
                if(sum != 15)continue;
                
                sum = 0;
                for(int p=0; p<=2; p++)
                {
                    sum += grid[i+p][j+1];
                }
                if(sum != 15)continue;
                
                sum = 0;
                for(int p=0; p<=2; p++)
                {
                    sum += grid[i+p][j+2];
                }
                if(sum != 15)continue;
                
                sum = 0;
                sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                if(sum != 15)continue;
                sum = 0;
                sum = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                if(sum != 15)continue;
                
                //重复的数字不符合条件 && 0也是不可以出现的
                int temp = 0;
                distinct.clear();
                for(int p=0; p<=2; p++)
                    for(int q=0; q<=2; q++)
                    {
                        if(distinct.count(grid[i+p][j+q]) > 0 || grid[i+p][j+q] == 0 || grid[i+p][j+q] >= 10) //这里好多笔误
                        {
                            temp++;
                        }else
                        {
                            distinct.insert(grid[i+p][j+q]);//这里笔误了，写成grid[p][q]了
                        }
                    }
                
                if(temp < 1)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};
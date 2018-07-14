class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        
        vector<vector<int>> smoother;
        //不初始化，会出现空指针类型的结构体错误
        smoother.resize(M.size());//M.size()行
        for(int i=0; i<M.size(); i++)
        {
            smoother[i].resize(M[i].size());//M[i].size()列
        }
        
        int sum = 0;
        int temp = 0;
        
        for(int i=0; i<M.size(); i++)
        {
            
            for(int j=0; j<M[i].size(); j++)
            {
                sum = 0; //不要写到上一层去了
                temp = 0;
                //第i-1行
                if(i-1 >=0)
                {
                    if(j-1 >=0)
                    {
                        sum = sum + M[i-1][j-1];
                        temp = temp + 1;
                    }
                    
                    sum = sum + M[i-1][j];
                    temp = temp + 1;
                    
                    if(j+1 < M[i].size())
                    {
                        sum = sum + M[i-1][j+1];
                        temp = temp + 1;
                    }
                }
                //与i同一行
                if(j-1 >=0)
                {
                    sum = sum + M[i][j-1];
                    temp = temp + 1;
                }

                sum = sum + M[i][j];
                temp = temp + 1;

                if(j+1 < M[i].size())
                {
                    sum = sum + M[i][j+1];
                    temp = temp + 1;
                }
                //第i+1行
                if(i+1 < M.size())
                {
                    if(j-1 >=0)
                    {
                        sum = sum + M[i+1][j-1];
                        temp = temp + 1;
                    }
                    
                    sum = sum + M[i+1][j];
                    temp = temp + 1;
                    
                    if(j+1 < M[i].size())
                    {
                        sum = sum + M[i+1][j+1];
                        temp = temp + 1;
                    }
                }
                
                smoother[i][j] = floor(sum/temp);
            }
        }
        
        return smoother;
    }
};
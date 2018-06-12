class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<vector<int> > out;
        std::vector<int> in;
        std::vector<int> temp;

        
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j > 0 & j != i)
                {
                    in[j] = temp[j] + temp[j-1];
                }else
                {
                    //in.push_back(1);
                    //上面这一行是错误的，因为当i > 时，是不需要在末尾加上一个1的。
                    //这就是为什么之前运行，每个子数组后面都有一长串1的原因
                    if (i == 0 | j == i) 
                    {
                        in.push_back(1);
                    }
                    
                }
            }
            temp = in;
            out.push_back(in);
            //in = [];
        }
        
        return out;
    }
};
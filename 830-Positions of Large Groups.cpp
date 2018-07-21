class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        
        std::vector<vector<int>> pos;
        std::vector<int> elem;
        elem.resize(2);//elem的长度固定为2
        if(S.size() <= 2)return pos;
        int count = 1;
       
        for(int i=1; i<S.size(); i++)
        {
            if(S[i] == S[i-1])
            {
                count++;
                if(count == 3)
                {
                    elem[0] = i-2;
                }
                //最后一位数是满足条件的需要特别考虑，但是要注意>=3这个条件
                if(count >= 3)
                {
                    if(i == S.size()-1)
                    {
                        elem[1] = i;
                        pos.push_back(elem);
                    }
                }
                
            }else
            {
                if(count >= 3)
                {
                    elem[1] = i-1;
                    pos.push_back(elem);
                }
                count = 1;
            }
            
        }
        
        return pos;
    }
};
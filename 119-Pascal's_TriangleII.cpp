class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        std::vector<int> arrayNum;
        std::vector<int> temp;
        
        for (int i = 0; i <= rowIndex; i++)
        {
            arrayNum.push_back(0);
        }
        temp = arrayNum;
        
        for (int i = 0; i <= rowIndex; i++)
        {
            
            for(int j = 0; j <= i; j++)
            {
                if(j >= 1 & j != i)
                {
                    arrayNum.at(j) = temp.at(j) + temp.at(j-1);
                }else
                {
                    arrayNum.at(j) = 1;
                } 
            }
            temp = arrayNum;
            
        }
        return arrayNum;
    }
};
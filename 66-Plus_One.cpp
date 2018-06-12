class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        std::vector<int> digitsPlusOne;
        int val = 0;
        int temp = 0;
        int insertVal = 0;
        
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            if (i == digits.size() -1 )
            {
                val = digits.at(i) + temp + 1;
            }else
            {
                val = digits.at(i) + temp;
            }
            
            temp = val / 10;
            insertVal = val % 10;
            digitsPlusOne.insert(digitsPlusOne.begin(), insertVal);
            
            if (i == 0 & temp != 0)
            {
                digitsPlusOne.insert(digitsPlusOne.begin(), temp);
            }
        }
        
        return digitsPlusOne;
        
    }
};
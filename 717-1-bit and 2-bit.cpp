class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        bool mark;
        for(int i=0; i<bits.size(); i++)
        {
            if(bits[i] == 1)
            {
                i++;
                if(i == bits.size()-1)
                    mark = false;
            }else
            {
                if(i == bits.size()-1)
                    mark = true;
            }
        }
        
        return mark;
    }
};
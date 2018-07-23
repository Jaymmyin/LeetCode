class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int maxEmpty = 0;
        int temp = 0;
        int startMax=0, endMax=0;//先找到首尾出现最大连续空位的数量
        int maxTemp=0;
        
        for(int i=0; i<seats.size(); i++)
        {
            if(seats[i] == 1)
            {
                break;
            }else
            {
                startMax++;
            }
        }
        for(int i=seats.size()-1; i>=0; i--)
        {
            if(seats[i] == 1)
            {
                break;
            }else
            {
                endMax++;
            }
        }
        
        maxTemp = max(startMax, endMax);
        
        for(int i=0; i<seats.size(); i++)
        {
            if(seats[i] == 1)
            {
                temp = 0;
            }else
            {
                temp++;
                if(temp > maxEmpty)
                {
                    maxEmpty = temp;
                }
            }
        }
        maxEmpty = max(maxTemp, (maxEmpty+1)/2);
        
        return maxEmpty;
        
    }
};
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int count = 0;
        while(count <= flowerbed.size()-1)
        {
            if(flowerbed[count] == 1) //如果该位置已经种植了，则直接跳过，判断下一个位置
            {
                count++;
            }else
            {
                //前面一个是否种植
                if(count != 0 && flowerbed[count-1] == 1)
                {
                    count++;
                }else
                {
                    if(count == flowerbed.size()-1) //count已经数到flowerbed最后一位了
                    {
                        n--;
                        flowerbed[count] = 1;
                        count++;
                    }else
                    {
                        if(flowerbed[count+1] == 1)
                        {
                            count++;
                        }else
                        {
                            n--;
                            flowerbed[count] = 1;
                            count++;
                        }
                    }
                    
                }
            }
        }
        
        if(n <= 0)
        {
            return true;
        }else
        {
            return false;
        }
        
    }
};
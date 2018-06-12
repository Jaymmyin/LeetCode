class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       
        std::vector<int> noRepeat;
        std::vector<int> noRepeatIndex;
        std::vector<int> index;
        int length = numbers.size();
        
        for(int i = 0; i < length - 1; i++)
        {
            if (numbers.at(i) == numbers.at(i + 1))
            {
                if(i == 0)  //first number must be in the final vector
                {
                    noRepeat.push_back(numbers.at(i));
                    noRepeatIndex.push_back(i + 1);
                }
                else if( numbers.at(i-1) != numbers.at(i)) // ignore the number that between the equal numbers
                {
                    noRepeat.push_back(numbers.at(i));
                    noRepeatIndex.push_back(i + 1);
                    if((i + 1) == length -1)    //last number must be in the final vector
                    {
                        noRepeat.push_back(numbers.at(i + 1));
                        noRepeatIndex.push_back(i + 2);
                    }
                }else if((i + 1) == length -1) //last number must be in the final vector
                {
                    noRepeat.push_back(numbers.at(i + 1));
                    noRepeatIndex.push_back(i + 2);
                }
            }else
            {
                noRepeat.push_back(numbers.at(i));
                noRepeatIndex.push_back(i + 1);
                if(i + 1 == length - 1)
                {
                    noRepeat.push_back(numbers.at(i + 1));
                    noRepeatIndex.push_back(i + 2);
                }
            }
        }
        
        int length2 = noRepeat.size();
        
        for(int i = 0; i < length2 - 1; i++) // get the index added equal to the target.
        {
            for(int j = i + 1; j < length2; j++)
            {
                if (noRepeat.at(i) + noRepeat.at(j) == target)
                {
                    index.push_back(noRepeatIndex.at(i));
                    index.push_back(noRepeatIndex.at(j));
                }
            }
        }
        return index;
    }
};
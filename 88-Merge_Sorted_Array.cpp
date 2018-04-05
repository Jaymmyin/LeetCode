class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //02.这个方法逻辑稍微复杂一点，但是代码量简单一点
        
        int i = m - 1, j = n - 1;
        
        if(m != 0 && n != 0)
        {
            for (int k = m + n - 1; k >= 0; k--) //按照从大到小的顺序，放入数组nums1中
            {
                if (nums1[i] > nums2[j] && i>= 0)
                {
                    nums1[k] = nums1[i--];
                }else if (j >= 0)
                {
                    nums1[k] = nums2[j--];
                }
            }
        }else if(m == 0)
        {
            nums1 = nums2;
        }
        
        /*
        //01. 这个方法思路简单，但是要写的代码较多
        int i = 0, j = 0;
        //int m = mums1.size();
        //int n = nums2.size();
        std::vector<int> nums;
        
        while(i < m || j < n)
        {
            if (i < m && j < n)
            {
                if(nums1[i] < nums2[j])
                {
                    nums.push_back(nums1[i]);
                    i++;
                }else
                {
                    nums.push_back(nums2[j]);
                    j++;
                }
            }else if (i < m)
            {
                nums.push_back(nums1[i]);
                i++;
            }else if(j < n)
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        
        nums1 = nums;
        */
    }
};
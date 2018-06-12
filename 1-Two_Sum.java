class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            map.put(nums[i], i);
        }
        
        for(Integer j = 0; j < nums.length; j++){
            Integer temp = target - nums[j];
            if (map.containsKey(temp) & (map.get(temp) != j)){
                int[] R;
                R = new int[2];
                R[0] = j;
                R[1] = map.get(temp);
                return R;
            }
        }
        throw new IllegalStateException("No such two numbers.");
    }
}
class Solution {
    public boolean isPalindrome(int x) {
        
        if (x < 0 | ((x % 10 == 0) & (x > 10))){
            return false;
        }else if(x < 10){
            return true;
        }
        int lengthX = 0;
        int reverseNumber = 0;
        int xx = 0;
        
        xx = x;
        
        while (xx != 0){
            xx = xx / 10;
            lengthX++;
        }
        
        int JO = 0; //说明x的位数是基数位还是偶数位
        JO = lengthX % 2;
        int j = 0;
        
        if (JO == 0){
            while (x > reverseNumber){
                j = x % 10;
                x = x / 10;
                reverseNumber = reverseNumber * 10 + j;
            }
            if (x == reverseNumber){
                return true;
            }else{
                return false;
            }
        }else{
            while (x > reverseNumber){
                j = x % 10;
                x = x / 10;
                reverseNumber = reverseNumber * 10 + j;
            }
            reverseNumber = reverseNumber / 10;
            if (x == reverseNumber){
                return true;
            }else{
                return false;
            }
        }
    }
}
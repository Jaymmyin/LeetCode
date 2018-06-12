class Solution {
    public int reverse(int x) {
        int j;
        long r = 0;
        if (x > 0){
            while(x != 0){
                j = x % 10;
                x = x / 10;
                r = r * 10 + j;
            }
            if (r <= 2147483647){
                return (int)r;
            }else{
                return 0;                
            }

        }else{
            while(x != 0){
                j = x % 10;
                x = x / 10;
                r = r * 10 + j;
        }
            if (r >= -2147483648){
                return (int)r;
            }else{
                return 0;                
            }
    }
}
}
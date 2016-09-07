#include <string>
class Solution {
public:
    int reverse(int x) {
        //check for overflow
        long long n = x;
        long long result = 0;
            
        long long base = 1;
        int remainder = 0;
        
        x /= 10;
        
        while(x != 0){
            x /= 10;
            base *= 10;
        }
        
        while(n != 0){
            remainder = n % 10;
            result += remainder * base;
            base /= 10;
            n /= 10;
        }
        
        if(result > INT_MAX || result < INT_MIN)
            return 0;
            
        return result;
    }
};
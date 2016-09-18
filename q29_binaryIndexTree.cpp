#include <cstdlib>
class Solution {
public:
    int divide(int dividend, int divisor) {
        //overflow cases
        if(divisor==0||(dividend==INT_MIN&&divisor==-1))
            return INT_MAX;
            
        int sign = ((dividend>0)^(divisor>0))?-1:1;
        long long v = labs(dividend);
        long long s = labs(divisor);
        int ans;
        
        while(v>=s){
            long long temp = s, times = 1;
            //shift operator
            while(v>=(temp<<1)){
                times <<=1;
                temp <<=1;
            }
            
            v -= temp;
            ans += times;
        }
        
        return (sign==1?ans:-ans);
    }
};
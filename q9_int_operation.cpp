class Solution {
public:
bool isPalindrome(int x) {
    if(x<0)
        return false;
    
    int a = x;
    int base = 1;
    
    a/=10;
    
    while(a!=0){
        base *= 10;
        a/=10;
    }
    
    while(x != 0){
        if(x%10==x/base){
            //if base is less than 100,
            //this number is palindrome
            if(base < 100)
                break;
            //eliminate the first digit
            x = x%base;
            base /=100;
            //eliminate last digit
            x = x/10;
        }else
            return false;
    }
    
    return true;
    
}
};
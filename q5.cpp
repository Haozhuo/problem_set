#include <algorithm>
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength = 0;
        int start = 0;
        string longest = "";
        
        for(int i = 0; i < s.size(); i++){
            //expand aroun center
            int length1 = expand(s,i,i);
            int length2 = expand(s,i,i+1);
            int len = max(length1,length2);
            
            if(maxlength < len){
                start = i - (len-1)/2;
                longest = s.substr(start,len);
                maxlength = len;
            }
        }
        
        return longest;
    }
private:
    int expand(string s, int l, int r){
        int b = l, e = r;
        while(b >= 0 && e < s.size() && s[b] == s[e]){
            b--;
            e++;
        }

        return e-b-1;
    }
};
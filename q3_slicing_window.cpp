#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int i = 0, j = 0;
        int length = s.size();
        
        unordered_set<char> container;
        unordered_set<char>::iterator p;
        
        while(i < length && j < length){
            p = container.find(s[j]);
            if(p == container.end()){
                container.insert(s[j]);
                if(maxLength < j-i+1)
                    maxLength = (j - i + 1);
                j++;
            } else{
                container.erase(s[i]);
                i++;
            }
        }
        
        return maxLength;
    }
};
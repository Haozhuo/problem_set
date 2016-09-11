#include <algorithm>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        
        string longest = strs[0];
        for(int i = 1; i < strs.size(); i++){
            if(longest.size() > strs[i].size())
                longest = longest.substr(0,strs[i].size());
                
            for(int k = 0; k < min(strs[i].size(),longest.size()); k++){
                if(longest[k]!=strs[i][k]){
                    longest = longest.substr(0,k);
                    break;
                }    
            }
        }
        
        return longest;
    }
};
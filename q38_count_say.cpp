class Solution {
public:
    string countAndSay(int n) {
        if(n==0)
            return "";
            
        string ans = "";    
            
        if(n==1)
            return "1";
        
        string before = countAndSay(n-1);
        
        int counter = 1;
        int i = 0;
        
        for(i = 0; i < (before.size()-1); i++){
            if(before[i]==before[i+1])
                counter++;
            else{
                ans += (to_string(counter) + before[i]);
                counter = 1;
            }
        }
        
        ans += (to_string(counter) + before[i]);
        
        return ans;
        
    }
};
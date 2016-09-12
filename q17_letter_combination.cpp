#include <unordered_map>
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result(0);
        
        if(digits.size()==0)
            return result;
        
        unordered_map<char,string> m({{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});
        
        for(int i = 0; i < digits.size(); i++){
            if(i==0){
                string s = m.find(digits[i])->second;
                
                for(int j = 0; j < s.size(); j++)
                    result.push_back(s.substr(j,1));
                
            }else{
                result = letter(m,result,digits[i]);
            }
        }
        
        return result;
        
    }
    
private:
    vector<string> letter(unordered_map<char,string>&map, const vector<string>& before, char digit){
        vector<string> ans(0);
        
        unordered_map<char,string>::iterator p = map.find(digit);
        
        if(p!=map.end()){
            string s = p->second;
            //add each one of char of the string represented by new digits
            //to each one of strings in the vector before
            for(int i = 0; i < before.size(); i++){
                for(int j = 0; j < s.size();j++){
                    ans.push_back(before[i]+s[j]);
                }
            }
            
            return ans;
        }else{
            return ans;
        }
        
    }
};
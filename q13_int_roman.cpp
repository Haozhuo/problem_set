#include <unordered_map>


class Solution {
public:
    int romanToInt(string s) {
        if(s=="")
            return 0;
        
        unordered_map<string,int> m;
        unordered_map<string,int>::iterator p;
        int result = 0;
        
        string c[13]= {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int nums[13] = {1000,900, 500,400,100, 90, 50,  40,  10,  9,  5,  4, 1};
        
        for(int i = 0; i < 13;i++){
            m.insert(make_pair(c[i],nums[i]));
        }
        
        for(int i = 0 ; i < s.size() -1;){
            p = m.find(s.substr(i,2));
            if(p != m.end()){
                result += (p->second);
                i+=2;
                continue;
            }else{
                p = m.find(s.substr(i,1));
                if(p!=m.end()){
                    result += (p->second);
                    i++;
                    continue;
                }
            }
        }
        
        int len = s.size();
        if(len<2){
            p = m.find(s.substr(0));
            result += (p->second);
            return result;
        }
        
        if(m.find(s.substr(len-2)) != m.end())
            return result;
        else{
            //if last two is not found, add the last one
            p = m.find(s.substr(len-1));
            result += (p->second);
            return result;
        }
        
    }
};
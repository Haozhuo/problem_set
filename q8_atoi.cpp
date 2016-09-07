#include <cctype>
#include <iostream>
class Solution {
public:
     int myAtoi(string str) {
        long long result = 0;
        long long base = 1;
        int start = 0;
        
        int i = 0;
        
        for(i = 0; i < str.size() && str[i] == ' '; i++)
            continue;
        
        if(i >= str.size())
            return 0;
        
        start = i;
        
        if(str[start]=='.')
            return 0;
        int j = 0;
        for(j = i; j < str.size(); j++){
            if((str[start]=='-' || str[start]=='+')&&j==start)
                continue;
            
            if(!isdigit(str[start]) && str[start]!='-'&&str[start]!='+')
                return 0;
            
            if(str[j]==' ')
                break;
            
            if(str[j]=='.')
                break;
            
            if(!isdigit(str[j]))
                break;
        }
        
        
        int counter = 0;
        if(str[start]=='-' || str[start]=='+'){
            counter = j - start - 2;
        }else{
            counter = j - start - 1;
        }
        
        if(counter < 0)
            return 0;
        
        while(counter > 0)
        {
            if(base >= INT_MAX)
                return str[start]=='-'?INT_MIN:INT_MAX;
            base *= 10;
            counter--;
        }
        
        for(int k = start; k < j; k++){
            if(result > INT_MAX || -result < INT_MIN)
                return str[start]=='-'?INT_MIN:INT_MAX;
            if(str[k]=='-' || str[k]=='+')
                continue;
            
            result += base *(str[k]-'0');
            base /= 10;
        }
        
        if(result > INT_MAX || -result < INT_MIN)
            return str[start]=='-'?INT_MIN:INT_MAX;
        
        return str[start] =='-'?-result:result;
    }
};
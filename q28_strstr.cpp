#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay_size = haystack.size();
        int needle_size = needle.size();
        
        if(needle_size==0){
            return 0;
        }
        
         for(int i = 0; i < (hay_size-needle_size+1); i++){
            if(haystack[i]==needle[0]){
                string sub = haystack.substr(i,needle_size);
                if(sub==needle)
                    return i;
            }
        }
        
        return -1;
    }
    //second approach
        int strStr2(string haystack, string needle) {
        int hay_size = haystack.size();
        int needle_size = needle.size();
        
        if(needle_size==0){
            return 0;
        }
        
        int start = -1;
        int j = 0;
        
         for(int i = 0; i < (hay_size-needle_size+1); i++){
            j = 0;
            if(haystack[i]==needle[0]){
                start = i;
                i++;
                j++;
                while(i<hay_size&&j<needle_size){
                    if(haystack[i]==needle[j]){
                        i++;
                        j++;
                    }else
                        break;
                }
                
                if(j==needle_size)
                    return start;
                else
                    i=start;
            }
        }
        
        return -1;
    }
};
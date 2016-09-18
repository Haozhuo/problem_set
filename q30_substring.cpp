#include <unordered_map>
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> res;
    if(words.size()==0 || s.size()==0)
        return res;
    
    
    int word_len = words[0].size();
    
    unordered_map<string,int> um;
    unordered_map<string,int>::iterator umi;
    
    //initialize the occurence of each words
    //inside vector words
    for(int i = 0; i < words.size(); i++)
        um[words[i]]++;
    
    int i = 0, start = 0, count = 0;
    bool first_time = true;
    unordered_map<string,int> occured_map;
    
    while(i < s.size()){
        //reset variables
        if(count==words.size()){
            res.push_back(start);
            occured_map.clear();
            count = 0;
            first_time = true;
            i = start + 1;
            continue;
        }
        
        string sub = s.substr(i,word_len);
        if(um.count(sub)){
            if(first_time){
                start = i;
                first_time = false;
            }
            
            occured_map[sub]++;
            if(um[sub]>=occured_map[sub]){
                i += word_len;
                count++;
            }else{
                occured_map.clear();
                count=0;
                first_time=true;
                i=start+1;
            }
        }else{
            occured_map.clear();
            count=0;
            //if that's the first word being examined 
            //but it's not found, increment i
            if(first_time)
                i++;
            //else, this means at least 1 word is matched
            else
                i=start+1;
            first_time=true;
        }
    }
    
    if(count==words.size())
        res.push_back(start);
    
    return res;      
    }
};
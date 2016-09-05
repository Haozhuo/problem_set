#include <unordered_map>

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    vector<int> result;
    unordered_map<int,int>::iterator p;

    for(int i = 0; i < nums.size(); i++){
      //here the order of index and value is reversed
      //because map.find can only find whether
      //there is key in map
      map.insert(make_pair(nums[i],i));
    }

    for(int i = 0; i < nums.size();i++){
      p = map.find(target-nums[i]);
      if(p != map.end() && p->second != i){
        result.push_back(i);
        result.push_back(p->second);
        return result;
      }
    }

    return result;
  }
};

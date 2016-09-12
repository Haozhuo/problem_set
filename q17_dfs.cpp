#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

#include <unordered_map>
class Solution {
public:
 vector<string> letterCombinations(string digits) {
    unordered_map<char, string> m = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"},
    {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};

    vector<string> ans(0);

    dfs(digits,m,0,"",ans);

    return ans;

  }

 private:
    void dfs(string digits, unordered_map<char, string> m, int index, string path, vector<string>& ans){
  	if(!path.empty()&&path.size()==digits.size()){
  		ans.push_back(path);
  		return;
  	}

  	for(int i = 0; i < m[digits[index]].size(); i++){
  		//depth first
  		path.push_back(m[digits[index]][i]);
  		dfs(digits,m,index+1,path,ans);
  		//pop back
  		path.pop_back();
  	}
  }
};
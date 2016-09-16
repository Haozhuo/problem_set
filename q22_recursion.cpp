/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans(0);
        
        if(n==0)
            return ans;
        
        add(ans,"",n,n);
            
        return ans;
    }
    
private:
    void add(vector<string>& v, string s, int left_p, int right_p){
        if(left_p==0&&right_p==0){
            v.push_back(s);
            return;
        }
        
        if(left_p>0)
            add(v,s+"(",left_p-1,right_p);
        
        if(left_p<right_p)
            add(v,s+")",left_p,right_p-1);
    }
};
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans(0);
        int maxDepth = 0;
        
        if(n==0)
            return ans;
        
        add(ans,"",n,n,maxDepth);
            
        return ans;
    }
    
private:
    void add(vector<string>& v, string s, int left_p, int right_p,int& depth){
        if(left_p==0&&right_p==0){
            v.push_back(s);
            cout << depth << endl;
            return;
        }
        
        if(left_p>0)
            add(v,s+"(",left_p-1,right_p,depth+1);
        
        if(left_p<right_p)
            add(v,s+")",left_p,right_p-1,depth+1);

        depth++;
    }
};
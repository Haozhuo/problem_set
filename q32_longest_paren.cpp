#include <stack>
class Solution {
public:
int longestValidParentheses(string s) {
    if(s.size()<2)
        return 0;
        
    stack<int> st;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='(')
            st.push(i);
        else if(s[i]==')'){
            if(!st.empty() && s[st.top()]=='(')
                st.pop();
            else
                st.push(i);
        }
    }
    
    int max = 0;
    
    if(st.empty())
        return s.size();
    else{
        int n1 = s.size(), n2 = 0;
        while(!st.empty()){
            n2 = st.top();
            st.pop();
            if((n1-n2-1)>max)
                max = n1 - n2 - 1;
            n1=n2;
        }
        n2 = 0;
        if(n1>max)
            max = n1;
        
        return max;
    }
}
};
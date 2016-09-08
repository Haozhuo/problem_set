    #include <iostream>
	#include <string>
	using namespace std;

    bool isMatch(string s, string p) {
        if(p.empty())
        	return s.empty();
        //if p has length less than 2, p[1] will return null
        //if p or s does not have index i, s.substr(i) will return null
        if(p[1]=='*'){
        	//isMatch(s,p.substr(2)): case when .* does not match anything
        	// !s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p): case when .* starts to match
        	return isMatch(s,p.substr(2)) || !s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p);
        }else{
        	return !s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p.substr(1));
        }
    }

    int main(){
    	string s1="ab";
    	string s2=".*";
    	if(isMatch(s1,s2))
    		cout << "Yeah" << endl;
    }
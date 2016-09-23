#include <unordered_set>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> sub_box;
            for(int j = 0; j < 9; j++){
                if(board[i][j]!='.'&&row.find(board[i][j])!=row.end()){
                    cout << board[i][j] << endl;
                    cout << "false 1" << endl;
                    return false;
                }
                else
                    row.insert(board[i][j]);
                    
                if(board[j][i]!='.'&&col.find(board[j][i])!=col.end()){
                    cout << "false 2" << endl;
                    return false;
                }
                else
                     col.insert(board[j][i]);
                //use 3*(i/3) to maintain the row
                //use 3*(i%3) to maintain the column
                //draw a diagram if not clear
                int currRow = 3 * (i/3);
                int currCol = 3 * (i%3);
                
                //use j/3 to traverse rows in a SINGLE subbox
                //use j%3 to traverse cols in a SINGLE subbox
                if(board[currRow+j/3][currCol+j%3]!='.'&&sub_box.find(board[currRow+j/3][currCol+j%3])!=sub_box.end()){
                    cout << board[currRow+j/3][currCol+j%3] << endl;
                    cout << "false 3" << endl;
                    return false;
                }
                else
                    sub_box.insert(board[currRow+j/3][currCol+j%3]);
            }
        }
       
        return true;
    }

};





//brute force approach
#include <unordered_set>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()==0){
            cout << "false 1" << endl;
            return true;
        }
        if(board.size() != 9){
            cout << "false 2" << endl;
            return false;
        }
        //determine each row is valid or not
        for(int i = 0; i < board.size(); i++){
            if(!isValid(board[i])){
                cout << "false 3" << endl;
                return false;
            }
        }
        //determine each col is valid or not
        for(int i = 0; i < board[0].size(); i++){
            vector<char> col;
            for(int j = 0; j < board.size(); j++){
                col.push_back(board[j][i]);
            }
            
            if(!isValid(col)){
                cout << "false 4" << endl;
                return false;
            }
        }
        
        //determine each subbox is valid or not
        for(int i = 0; i < 3; i++){
            vector<char> box;
            for(int j = 0; j < 9; j++){
                for(int k = i*3; k < (i*3+3); k++){
                    box.push_back(board[j][k]);
                }
                
                if(j % 3==2){
                    if(!isValid(box)){
                        cout << "false 5" << endl;
                        return false;
                    }
                    else
                        box.clear();
                }
            }
        }
        
        return true;
        
        
        
    }
private:
    bool isValid(vector<char> row){
        unordered_set<char> us;
        if(row.size() != 9)
            return false;
        
        for(int i = 0; i < row.size(); i++){
            if(row[i]=='.')
                continue;
                
            if(us.find(row[i]) != us.end())
                return false;
            else
                us.insert(row[i]);
        }
        
        return true;
    }

};
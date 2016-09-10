    string intToRoman(int num) {
        string c[13]= {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"}; 
        int nums[13] = {1000,900, 500,400,100, 90, 50,  40,  10,  9,  5,  4, 1};
        
        string result="";
        
        for(int i = 0; i <= 12; i++){
            if(num != 0){
                for(int j = 0; j < num/nums[i]; j++)
                    result += c[i];
                num %= nums[i];
            }else
                break;
        }
        
        return result;

    }
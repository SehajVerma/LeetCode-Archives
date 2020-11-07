class Solution {
public:
    void keypad(string digits,string nums[],vector<string>&res,int i,string output)
    {
        if(i==digits.length())
        {
            res.push_back(output);
            return;
        }
        
        string pd = nums[digits[i]-'0'];
        for(int j=0;j<pd.length();j++)
        {
            keypad(digits,nums,res,i+1,output+pd[j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
       if(digits.length()==0)
           return res;
        
        string nums[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        keypad(digits,nums,res,0,"");
        return res;
    }
};

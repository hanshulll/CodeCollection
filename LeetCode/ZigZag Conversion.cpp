class Solution {
public:
    string convert(string s, int numRows) {
        vector <string> temp(numRows, "");
        int row = 0, direction = 1;
        string ans = "";
        
        if(numRows == 1)
            return s;
        
        for(int i = 0; i < s.size(); i++)
        {
            temp[row] += s[i];
            
            if(row == numRows - 1)
                direction = -1;
            if(row == 0)
                direction = 1;
            
            row += direction;
            
        }     
        
        for(int i = 0; i < numRows; i++)
        {
            ans += temp[i];
        }
        
        return ans;
    }
};

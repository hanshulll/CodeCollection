 class Solution {
        private:
        vector<string> str={"","","abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> Getanswer;

public:
      passing by reference ⬇️ so copies are not made at each function call
void answer(string digits ,int counter , string &ans){
    if(counter == digits.size()){

        Getanswer.push_back(ans);
        return ;
    }
    char ch = digits[counter];
    string chars = str[ch-'0'];

    for(int i =0;i<chars.size();i++){
        ans.push_back(chars[i]);     // add a character from str for current position,
        answer(digits,counter+1,ans); // // and recurse for next positions
        ans.pop_back();   // backtrack
        }

}
    vector<string> letterCombinations(string digits) {
    if(digits.size()==0){
            return Getanswer;
        }   
string ans="";


             answer(digits, 0 ,ans);



         return Getanswer;

    }
};
/*Time Complexity : O(4^N), where N, is the length of input string. 4^N for building every possible string combination .. Here, 4 is chosen assuming the worst case where each digit will be 7 or 9 and we would have 4*4*4*4 total string combinations.
Space Complexity : O(N), the max recursion depth will be N, where N is the length of input string. If the space required for ans is considered as well, the complexity will be O(4^N).
*/
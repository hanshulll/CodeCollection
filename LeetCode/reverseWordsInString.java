class Solution {
    public String reverseWords(String s) {
        String st[] = s.trim().split(" ");
        String res = "";
        for(String S:st) 
            if(!S.equals("")) res = S+" "+res;
        return res.trim();
    }
}

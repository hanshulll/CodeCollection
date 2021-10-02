public class lengthOfLongestSubstring {
        public static int lengthOflongestSubstring(String s) {
            if (s.length() <= 1)
                return s.length();
    
            int n = s.length(), si = 0, ei = 0, count = 0, len = 0;
            int[] freq = new int[128]; // vector<int> freq(128,0);
    
            while (ei < n) {
                if (freq[s.charAt(ei)] == 1)
                    count++;
                freq[s.charAt(ei)]++;
                ei++;
    
                while (count > 0) {
                    if (freq[s.charAt(si)] == 2)
                        count--;
                    freq[s.charAt(si)]--;
                    si++;
                }
    
                len = Math.max(len, ei - si);
            }
    
            return len;
        }
    
        public static void main(String[] args){
            Scanner scn=new Scanner(System.in); 
            String str=scn.nextLine();
            System.out.println(lengthOflongestSubstring(str)); 
        }
    
    
}

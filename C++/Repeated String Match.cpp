   int repeatedStringMatch(string A, string B) 
    {
       // Your code goes here
       string s = A;
       
       if(A.find(B) != string::npos) return 1;
       
       int count = B.size() / A.size()+2;
        
       for(int i=2; i<=count; i++)
       {
           s+=A;
           if(s.find(B) != string::npos)
           return i;
       }
       return -1;
    }
  

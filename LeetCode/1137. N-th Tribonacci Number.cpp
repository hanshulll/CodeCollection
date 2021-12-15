//Dev Wadhwa @devwadhwa01

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n==1 || n==2) return 1;
        else{
            int arr[38];
            arr[0]=0;
            arr[1]=1;
            arr[2]=1;
            for(int i=3;i<n+1;i++)
            {
                arr[i]=arr[i-3]+arr[i-2]+arr[i-1];
            }
            return arr[n];
        }
    }
};

//Cannot use recursion because of TLE

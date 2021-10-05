int findMissing(int arr[], int n) { 
       
       int count=1;
       sort(arr,arr+n);
       for(int i=0; i<n; i++)
       {
           if(arr[i]>0)
           {
               if(arr[i]!=count)
               {
                   if(arr[i]==arr[i-1])
                        continue;
                    else
                        return count;
               }
               else
                  count++;
           }
       }
       if(count==(n+1))
            return count;
}

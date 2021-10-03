    #include<bits/stdc++.h>
    using namespace std;
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        int maxx = INT_MIN;
        int platform = 0;
        sort(arr,arr+n);
        sort(dep,dep+n);
        int i = 0; //pointer to arrival array
        int j = 0; //pointer to dept array
        while(i < n && j < n){ //traverse 1st array
            if(arr[i] > dep[j]){ //vacancy in one platform
                platform --;
                j++;
            }
            else if( arr[i] <= dep[j]){
                platform++;
                i++;
                maxx = max(maxx, platform);
            }
        }
        return maxx;
    }
    int main(){
        int n;
        int arr[100];
        int dept[100];
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(int i=0;i<n;i++){
            cin >> dept[i];
        }
        int ans = findPlatform(arr, dept, n); 
        cout << ans << endl;
        return 0;
    }
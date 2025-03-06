class Solution {
    public:
      vector<int> maxOfSubarrays(vector<int>& arr, int k) {
          //we will go till kth ele and have to return max among all
          //those in that subarr and make arr which have all such 
          //it is basically raw sliding window implentation as we have 
          //to push in ans arr max from k length window current
          // int n=arr.size();
          // vector<int>ans;
          // for(int i=0;i<=n-k;i++){
          //     int maxi=arr[i];
          //     for(int j=1;j<k;j++){
          //         if(arr[i+j]>maxi) maxi=arr[i+j];
          //     }
          //     ans.push_back(maxi);
          // }
          // return ans;
          //we have to optimize brute approach by using priority queue
          int n=arr.size();
          vector<int>ans;
          priority_queue<pair<int,int>>pq;
          
          for(int i=0;i<k;i++) pq.push({arr[i],i});
              
          ans.push_back(pq.top().first);
              
          for(int i=k;i<n;i++){
              pq.push({arr[i],i});
                  
              while(pq.top().second <= i-k) pq.pop();
                  
              ans.push_back(pq.top().first);
          }
          return ans;
      }
  };
  
  
//App- Using max heap (priority queue) for sliding window maximum
//TC- O(n log k) where n is array size and k is window size
//SC- O(k) for priority queue storage

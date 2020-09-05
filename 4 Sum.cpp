class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
         
        sort(nums.begin(),nums.end());
        for(auto i:nums)
            cout<<i<<" ";
        vector<vector<int>>v;
        if(n==0)
            return v;
        for(int i=0;i<n-3;i++)
        {
           if(i!=0 && nums[i]==nums[i-1]) continue;
           for(int j=i+1;j<n-2;j++)
           {
               if(j!=(i+1) && nums[j]==nums[j-1])continue;
               int sum1 = nums[i]+nums[j];
               int sum2 = target - sum1;
               int p=j+1;
               int q=n-1;
               while(p<q)
               {
                  int sum3 = nums[p]+nums[q];
                  if(sum2==sum3)
                  {
                     vector<int>temp;
                     temp.push_back(nums[i]);
                     temp.push_back(nums[j]);
                     temp.push_back(nums[p]);
                     temp.push_back(nums[q]);
                     v.push_back(temp);
                     p++;
                     q--;
                     while(p<q && nums[p]==nums[p-1])
                         p++;
                     while(p<q && nums[q]==nums[q+1])
                         q--; 
                  }
                  else if(sum3>sum2)
                        q--;
                      else
                        p++;
               }
           }
        }
        return v;
    }
};

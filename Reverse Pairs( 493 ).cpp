
class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high)
    {
        int count=0;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high)
        {
           if((long)nums[i]<=(long)2*nums[j])
           {
               i++;
           }
           else
           {
              count += (mid-i+1);
              j++;
           }
        }
        
        i=low;
        j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=high)
        {
           if(nums[i]<=nums[j])
           {
               temp.push_back(nums[i++]);
           }
           else
           {
              temp.push_back(nums[j++]);
           }
        }
        while(i<=mid)
        {
           temp.push_back(nums[i++]); 
        }
        while(j<=high)
        {
           temp.push_back(nums[j++]); 
        }
        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
        return count;
    }
    int mergesort(vector<int>&nums,int low,int high)
    {
        if(low>=high) return 0;
        int mid = (low+high)/2;
        int count = mergesort(nums,low,mid);
        count += mergesort(nums,mid+1,high);
        count += merge(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
        
    }
};

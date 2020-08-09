https://www.youtube.com/watch?v=p5Cm_r4T1Rw&t=147s

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        int n = A.size();
        int cnt=0;
        int prefix[30001]={0};
        prefix[0]=1;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=A[i-1];
            sum%=k;
            sum=(sum+k)%k;
            prefix[sum]++;
        }
        for(auto i : prefix)
        {
            cnt += (i)*(i-1) / 2;
        }
        return cnt;
    }
};

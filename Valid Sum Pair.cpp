https://practice.geeksforgeeks.org/contest-problem/valid-pair-sum/1/

int ValidPair(int* a, int n) 
{ 
    // code here 
    sort(a,a+n);
    int low=0;
    int high=n-1;
    int cnt=0;
    while(low<high)
    {
        if(a[low]+a[high]<=0)
        low++;
        else
        {
            cnt+=(high-low);
            high--;
        }
    }
    return cnt;
}

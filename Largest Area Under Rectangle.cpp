class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int n = heights.size();
        if(n==0) return 0;
        int max_area = INT_MIN;
        int topp=0;
        int i=0;
        for(i=0;i<n;i++)
        {
            if(s.empty() || heights[i]>=heights[s.top()])
                s.push(i);
            else
            {
                while(!s.empty() && heights[s.top()]>heights[i])
                {
                    topp=s.top();
                    s.pop();
                    max_area = max(max_area,heights[topp]*(s.empty()? i : i-s.top()-1));
                }
                s.push(i);
            }
        }
        while(!s.empty())
        {
            topp=s.top();
            s.pop();
            max_area = max(max_area,heights[topp]*(s.empty()? i : i-s.top()-1));
        }
        return max_area;
    }
};

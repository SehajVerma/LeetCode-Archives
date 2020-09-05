class Solution {
public:
    int LAR(vector<int> heights) {
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        vector<int>v(matrix[0].size(),0);
        int max_area=INT_MIN;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='0')
                    v[j]=0;
                else
                    v[j]+=1;
            }
            max_area = max(max_area,LAR(v));
        }
        return max_area;
    }
};

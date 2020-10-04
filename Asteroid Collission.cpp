class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        
        for(auto asteroid: asteroids){
            while(!ans.empty() && ans.back() > 0 && asteroid < 0){
                int temp = ans.back();
                ans.pop_back();
                if(abs(temp) > abs(asteroid)) asteroid = temp;
                else if(abs(temp) == abs(asteroid)) asteroid = 0;
            }
            if(asteroid) ans.push_back(asteroid);
        }
        return ans;
    }
};


//MY SOLUTION WITH STACK

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            if(s.empty())
                s.push(a[i]);
            else
            {
                if(a[i]<0)
                {
                  int flag=0;
                  while(!s.empty() && s.top()>=0)
                  {
                    int t = s.top();
                    if(t<abs(a[i]))
                    {
                       s.pop(); 
                    }
                    else{
                        if(t==abs(a[i]))
                            s.pop();
                        flag=1;
                        break;
                    }
                  }
                    if(!flag)
                    {
                        s.push(a[i]);
                    }
                }
                else
                    s.push(a[i]);
            }
        }
        int m = s.size();
        vector<int>out;
        while(!s.empty())
        {
            out.push_back(s.top());
            s.pop();
        }
        reverse(out.begin(),out.end());
        return out;
    }
};

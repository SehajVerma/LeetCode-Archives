https://github.com/bephrem1/backtobackswe/blob/master/Graphs/CloneAGraph/CloneAGraph.java
https://www.youtube.com/watch?v=vma9tCQUXk8

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<Node*,Node*>mp;
        queue<Node*>q;
        q.push(node);
        mp.insert({node,new Node(node->val)});
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for(auto nbh : curr->neighbors)
            {
                if(mp.find(nbh)==mp.end())
                {
                    mp[nbh]=new Node(nbh->val);
                    q.push(nbh);
                }
                mp[curr]->neighbors.push_back(mp[nbh]);
            }
        }
        return mp[node];
    }
};

//DFS solution
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};

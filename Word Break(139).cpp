class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> next;
    TrieNode(): isWord(false), next(vector<TrieNode*>(26, nullptr)) {}
};
class Solution {
public:
    TrieNode* buildTrie(vector<string> &wordDict) {
        TrieNode *root = new TrieNode();
        for (auto &word : wordDict) {
            TrieNode *p = root;
            for (auto &ch : word) {
                if (p->next[ch-'a'] == nullptr)
                    p->next[ch-'a'] = new TrieNode();
                p = p->next[ch-'a'];
            }
            p->isWord = true;
        }
        return root;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        TrieNode *root = buildTrie(wordDict);

        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 0; i <= len; i++) {
            if (dp[i]) {
                TrieNode *p = root;
                for (int j = i; j < len; j++) {
                    if (p->next[s[j]-'a'] == nullptr)
                        break;
                    p = p->next[s[j] - 'a'];
                    if (p->isWord)
                        dp[j+1] = true;
                }
            }
        }
        return dp[len];
    }
}

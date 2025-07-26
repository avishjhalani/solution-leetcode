class Solution {
public:
    struct Node {
        Node* link[26] = {nullptr};
        bool flag = false;

        bool contains(char c) {
            return link[c - 'a'] != nullptr;
        }

        void set(char c, Node* node) {
            link[c - 'a'] = node;
        }

        Node* get(char c) {
            return link[c - 'a'];
        }

        void send() {
            flag = true;
        }

        bool gend() {
            return flag;
        }
    };

    Node* root;

    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->set(c, new Node());
            }
            node = node->get(c);
        }
        node->send();
    }

    Node* sh(string word) {
        Node* node = root;
        for (char c : word) {
            if (!node->contains(c)) return nullptr;
            node = node->get(c);
        }
        return node;
    }

    void dfs(string& temp, Node* node, vector<string>& q) {
        if (q.size() == 3) return;  // Only top 3 suggestions
        if (node->gend()) q.push_back(temp);

        for (char c = 'a'; c <= 'z'; ++c) {
            if (node->contains(c)) {
                temp.push_back(c);
                dfs(temp, node->get(c), q);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Node();
        for (auto& word : products) insert(word);

        vector<vector<string>> ans;
        string temp = "";
        Node* node = root;

        for (char c : searchWord) {
            temp += c;
            node = node ? node->get(c) : nullptr;
            if (!node) {
                ans.push_back({});  
                continue;
            }

            vector<string> q;
            string path = temp;
            dfs(path, node, q); 
            ans.push_back(q);
        }

        return ans;
    }
};
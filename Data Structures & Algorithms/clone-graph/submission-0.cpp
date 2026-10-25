/*
// Definition for a Node.
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
        if(!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;
        oldToNew[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* cur = q.front(); 
            q.pop();
            for(Node* n: cur->neighbors){
                if(oldToNew.find(n) == oldToNew.end()){
                    oldToNew[n] = new Node(n->val);
                    q.push(n);
                }
                oldToNew[cur]->neighbors.push_back(oldToNew[n]);
            }
        }
        return oldToNew[node];
    }
};

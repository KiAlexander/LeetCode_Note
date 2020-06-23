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
// 深拷贝反应在本题中就是，所有的结点需要重新new出来，而不是直接赋值。
// 整体的思路依然是dfs，跑遍原图中每个结点，然后根据原结点生成新结点。
// 要注意的地方就是，因为图存在环，所以要标记访问过的结点，避免重复形成死循环：
// 如果该结点已经被访问过，则不再遍历该结点，而是直接将指针值赋给自己邻接点数组----浅拷贝；
// 如果该结点没有被访问过，则继续dfs遍历该结点，并将产生的新结点----深拷贝；
class Solution {
unordered_map<Node*,Node*> umap;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* root = new Node(node->val,node->neighbors);
        umap[node]=root;
        for(auto& next:root->neighbors) {
            if(umap[next]) next=umap[next];
            else next = cloneGraph(next);
        }
        return root;
    }
};
};
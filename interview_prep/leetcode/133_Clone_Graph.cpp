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
    
    unordered_map<Node*, Node*> mapOfOldAndNew;
    
public:
    Node* cloneGraph(Node* node) {
        
        if (!node)
            return nullptr;
        
        queue<Node*> nodeQ;
        nodeQ.push(node);
        Node *newNode;
        
        while(!nodeQ.empty()) {
            
            Node *currentNode = nodeQ.front();
            nodeQ.pop();
            
            if (mapOfOldAndNew.find(currentNode) == mapOfOldAndNew.end()) {
                newNode = new Node(currentNode->val);
                mapOfOldAndNew[currentNode] = newNode;
            }
            
            
            for(Node* neighborNode : currentNode->neighbors) {
                if (mapOfOldAndNew.find(neighborNode) == mapOfOldAndNew.end()) {
                    Node *newNeighbor = new Node(neighborNode->val);
                    mapOfOldAndNew[neighborNode] = newNeighbor;
                    nodeQ.push(neighborNode);
                }
                mapOfOldAndNew[currentNode]->neighbors.push_back(mapOfOldAndNew[neighborNode]);
            }
            
        }
        
        return mapOfOldAndNew[node];
        
    }
};

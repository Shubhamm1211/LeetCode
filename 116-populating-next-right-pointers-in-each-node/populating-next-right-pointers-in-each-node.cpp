/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        while(root){
            int s=q.size();
            if(s==0)return root;
            while(s>0){
                Node*front=q.front();
                q.pop();
                    if(s==1){
                        front->next=NULL;
                    }
                    else{
                    Node*temp2=q.front();
                    front->next=temp2;
                    }
                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                s--;
            }
        }
        return root;
    }
};
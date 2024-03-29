/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        function<Node*(int,int,int)> helper=[&](int x,int y,int len) -> Node*
        {
            if(len<=0) return NULL;
            for(int i=x;i<x+len;i++)
            {
                for(int j=y;j<y+len;j++)
                {
                    if(grid[i][j]!=grid[x][y])
                        return new Node(true,false,helper(x,y,len/2),helper(x,y+len/2,len/2),helper(x+len/2,y,len/2),helper(x+len/2,y+len/2,len/2));
                }
            }
            return new Node(grid[x][y]==1,true,NULL,NULL,NULL,NULL);
        };
        return helper(0,0,grid.size());
    }
};
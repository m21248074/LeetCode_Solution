class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color,int src)
    {
        if(color==src) return image;
        if(sr<image.size()&&sc<image[0].size())
        {
            if(image[sr][sc]==src)
            {
                image[sr][sc]=color;
                floodFill(image,sr-1,sc,color,src);
                floodFill(image,sr,sc-1,color,src);
                floodFill(image,sr+1,sc,color,src);
                floodFill(image,sr,sc+1,color,src);
            }
        }
        return image;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        floodFill(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int ini=image[sr][sc];
        dfs(image,sr,sc,m,n,color,ini);
        return image;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int m, int n,int color, int ini){
        if(i< 0 || j<0 || i>=m || j>=n) return;
        if(image[i][j]!=ini || image[i][j]==color) return;
        image[i][j]=color;
        dfs(image,i+1,j,m,n,color,ini);
        dfs(image,i-1,j,m,n,color,ini);
        dfs(image,i,j+1,m,n,color,ini);
        dfs(image,i,j-1,m,n,color,ini);
    }
};
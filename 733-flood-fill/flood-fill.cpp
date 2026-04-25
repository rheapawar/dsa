class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og = image[sr][sc];
        if(og != color) helper(image, sr, sc, color, og);
        return image;
        
    }

    void helper(vector<vector<int>> &image, int r, int c, int color, int og){
        if(image[r][c] == og) image[r][c] = color;
        else return;
        if(r > 0) helper(image, r-1, c, color, og);
        if(r < image.size()-1) helper(image, r + 1, c, color, og);
        if(c > 0) helper(image, r, c-1, color, og);
        if(c < image[0].size()-1) helper(image, r, c + 1, color, og);
        return;
    }
};
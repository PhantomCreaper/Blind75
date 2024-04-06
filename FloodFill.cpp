//733. Flood Fill
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        int oColor = image[sr][sc];
        fill(image, sr, sc, color, oColor);
        return image;
    }

    void fill(vector<vector<int>>& image, int sr, int sc, int color, int oColor) {
        if(sr<0 || sr>=image.size() || sc<0 || sc>= image[0].size() || image[sr][sc]==color || image[sr][sc]!=oColor){
            return;
        }

        image[sr][sc] = color;

        fill(image, sr-1, sc, color, oColor);
        fill(image, sr+1, sc, color, oColor);
        fill(image, sr, sc-1, color, oColor);
        fill(image, sr, sc+1, color, oColor);
    }
};
//I hated understanding this one

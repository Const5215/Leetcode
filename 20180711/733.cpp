class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int chose = image[sr][sc];
        if (chose == newColor)
            return image;
        queue<pair<int, int>> q;
        image[sr][sc] = newColor;
        q.push({sr,sc});
        while(q.size()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ni = i + dir[d][0], nj = j + dir[d][1];
                if (ni < 0 || ni >= image.size() || nj < 0 || nj >= image[0].size() || image[ni][nj] != chose)
                    continue;
                image[ni][nj] = newColor;
                q.push({ni,nj});
            }
        }
        return image;
    }
};
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long a = A, b = B, c = C, d = D, e = E, f = F, g = G, h = H;
        long long res = (c-a)*(d-b)+(g-e)*(h-f);
        long long Lx = max(a,e), Rx = min(c,g), Ly = max(b,f), Ry = min(d,h);
        long long dex = 0;
        if (Lx < Rx && Ly < Ry)
            dex = (Rx-Lx)*(Ry-Ly);
        return (int)(res-dex);
    }
};
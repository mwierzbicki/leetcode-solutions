// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ans=0,ny,nx,dod;
        if (points.size()==1) {
            return 1;
        }
        long double t;
        unordered_map<long double,int> h;
        for (int i=0; i<points.size(); i++) {
            dod=0;
            for (int j=0; j<points.size(); j++) {
                if (i!=j) {
                    ny=points[j].y-points[i].y;
                    nx=points[j].x-points[i].x;
                    if (ny==0 && nx==0) {
                        dod++;
                        ans=max(ans,dod+1);
                    }
                    else {
                        t=atan2l(ny,nx);
                        if (t<0) {
                            t+=M_PI;
                        }
                        h[t]++;
                        ans=max(ans,h[t]+1+dod);
                    }
                }
            }
            h.clear();
        }
        return ans;
    }
};

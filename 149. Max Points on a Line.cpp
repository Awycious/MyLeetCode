/* *********************************************************************************************** *
 *              Annie Wang 2016.11.28                                                              *
 * Idea: O(n^2) complexity, we have 3 types of points, visited, checking(only one) and unvisited.  *
 *      In each iteration, ignore the visited points, find the ratio of line between checking and  *
 *      unvisited points, and use map to record the # of occurence of each ratio. The output is    *
 *      the maximum among these numbers.                                                           *
 *                                                                                                 *
 * Remark: check if x is in map: map.find(x) != map.end();                                         *
 *         the element x corresponding to: map.find(x); // map.find(x)->second found in other webs *
 *         In the first trial, case of duplicate point and p1.x == p2.x was missed                 *
 * *********************************************************************************************** *
 */
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
        int len = points.size();
        if( len < 1) return 0;
        int opt = 1;
        for(int i = 0; i < len; i++){
            map<double, int> count;// the y/x ratio map to total point number
            int base = 1;
            int imax = 0;
            
            for(int j = i + 1; j < len; j++){
                Point p1 = points[i];
                Point p2 = points[j];
                if( p1.x == p2.x && p1.y == p2.y){
                    base++;
                } else {
                    double ratio12 = (p1.x == p2.x)? 0 : (double) (p2.y - p1.y) / (p2.x - p1.x);
                    if( count.find( ratio12 ) == count.end() ){
                        count[ ratio12 ] = 1;
                        if( imax == 0) imax = 1;
                    } else {
                        count[ ratio12 ]++;
                        if( count[ ratio12 ] > imax){
                            imax = count[ ratio12 ];
                        }
                    }
                }
            }
            opt = max(opt, imax + base);
            
        }
        return opt;
    }
};

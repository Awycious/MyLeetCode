/* ******************************************** *
 *      Annie Wang 2016.12.01                   *
 *  Idea: simple                                *
 *  Remark: N/A                                 *
 * ******************************************** *
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int a = 0;
        int b = 1;
        vector<int> opt(rowIndex + 1, 0);
        opt[0] = 1;
        opt[1] = 1;
        for(int i = 2; i < rowIndex + 1; i++){
            for(int j = 0; j <= i; j++){
                b = opt[j];
                opt[j] = a + b;
                a = b;
            }
        }
        return opt;
    }
};

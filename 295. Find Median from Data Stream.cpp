/* *********************************************************** *
 *      Annie Wang 2016.11.30                                  *
 *  Idea: create a sorted vector for data                      *
 *  Remark: 1. since every num can be the median in the future,*
 *          we cannot get and throw the data away, they must   *
 *          be stored at somewhere                             *
 *          2. double m = (2 + 3) / 2;                         *
 *          this will give m a value of 2 but 2.5              *
 * *********************************************************** *
 */
class MedianFinder {
private:
    vector<int> mynum;
    int len = 0;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        mynum.insert(mynum.begin() + len, num);
        len++;
        cout << "inserted";
    }

    // Returns the median of current data stream
    double findMedian() {
        if(len == 0) return NULL;
        if(len == 1) return mynum[0];
        sort(mynum.begin(), mynum.end());
        if(len%2 == 0){
            double m = mynum[len/2] + mynum[len/2 - 1];
            m /= 2;
            return m;
        } else{
            return mynum[len/2];
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

/* ****************************************************************** *
 *      Annie Wang 2016.12.02                                         *
 * Idea: using big enough arrays instead of stack, only need to       *
 *      change the head number(where the top is)                      *
 * Remark: fixed array is faster                                      *
 * Complains: I saw someone using build-in stack functions/(ㄒoㄒ)/~~ *
 *      How come this is allowed......  but I beats 86% forks:)       *
 * ****************************************************************** *
 */
class MinStack {
private: 
    int head = -1;
    int minhead = -1;
    int ms[8192];
    int mins[8192];
    
    
public:
    /** initialize your data structure here. */
    MinStack() {
        head = -1;
        minhead = -1;
    }
    
    void push(int x) {
        head++;
        ms[head] = x;
        if(minhead < 0 || (minhead > -1 && ms[mins[minhead]] > x)){
            minhead++;
            mins[minhead] = head;
        }
    }
    
    void pop() {
        if(head == mins[minhead]) minhead--;
        head--;
    }
    
    int top() {
        return ms[head];
    }
    
    int getMin() {
        return ms[mins[minhead]];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

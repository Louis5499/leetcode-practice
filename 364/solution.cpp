/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        // 1. Collect Depth
        int maximunDepth = maxDepth(nestedList, 1);
        
        // 2. Calc Weight
        return calcWeight(nestedList, 1, maximunDepth);
    }
    
    int maxDepth(vector<NestedInteger>& nestedList, int layer) {
        int maximun = layer;
        for (int i=0; i<nestedList.size(); i++) {
            if (!nestedList[i].isInteger()) maximun = max(maximun, maxDepth(nestedList[i].getList(), layer+1));
        }
        return maximun;
    }
    
    int calcWeight(vector<NestedInteger>& nestedList, int layer, int maximunDepth) {
        int sum = 0;
        for (int i=0; i<nestedList.size(); i++) {
            if (!nestedList[i].isInteger()) sum += calcWeight(nestedList[i].getList(), layer+1, maximunDepth);
            else sum += (maximunDepth-layer+1)*nestedList[i].getInteger();
        }
        return sum;
    }
};
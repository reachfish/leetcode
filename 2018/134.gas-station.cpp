/*
 * [134] Gas Station
 *
 * https://leetcode.com/problems/gas-station
 *
 * Medium (29.08%)
 * Total Accepted:    84790
 * Total Submissions: 291568
 * Testcase Example:  '[4]\n[5]'
 *
 * 
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i].
 * 
 * 
 * 
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from station i to its next station (i+1). You begin the journey with
 * an empty tank at one of the gas stations.
 * 
 * 
 * 
 * Return the starting gas station's index if you can travel around the circuit
 * once, otherwise return -1.
 * 
 * 
 * 
 * Note:
 * The solution is guaranteed to be unique.
 * 
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int start = 0;        
		int total = 0;
		int cur = 0;
		for(int end=0; end<gas.size(); end++){
			int left = gas[end] - cost[end];
			total += left;
			cur += left;
			while(start <= end && cur < 0){
				cur -= gas[start] - cost[start];
				start++;
			}
		}

		return total >= 0 ? start : -1;
    }
};

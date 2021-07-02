/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        clean(robot, visited, 0, 0, 0);
    }
    
    void clean(Robot& robot, unordered_set<string> &visited, int i, int j, int dir) {
        robot.clean();
        visited.insert(to_string(i)+"a"+to_string(j));
        
        for (int nowDir = dir; nowDir < dir+4; nowDir++) {
            int ni = dirs[nowDir%4][0] + i;
            int nj = dirs[nowDir%4][1] + j;
            if (visited.count(to_string(ni)+"a"+to_string(nj)) == 0 && robot.move()) {
                clean(robot, visited, ni, nj, nowDir%4);
                
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
};
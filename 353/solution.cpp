class SnakeGame {
public:
    int w, h, pos;
    vector<vector<int>> food;
    set<pair<int, int>> hist;
    deque<pair<int, int>> q;
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& _food) {
        w = width;
        h = height;
        pos = 0;
        q.push_back({ 0, 0 });
        food = _food;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int row = q.back().first, col = q.back().second;
        pair<int, int> d = q.front(); q.pop_front();
        hist.erase(d);

        if (direction == "U") row--;
        else if (direction == "L") col--;
        else if (direction == "R") col++;
        else if (direction == "D") row++;
        
        if (!inBorder(row, col) || hist.count({row, col})) return -1;
        q.push_back({row, col});
        hist.insert({row, col});
        
        if (pos >= food.size()) return food.size();
        
        if (row == food[pos][0] && col == food[pos][1]) {
            pos++;
            q.push_front(d);
            hist.insert(d);
        }
        
        return q.size()-1;
    }
    
    bool inBorder(int i, int j) {
        return i >= 0 && i < h && j >= 0 && j < w;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = n*2;
        unordered_map<int, char> m;

        for (auto r : reservedSeats)
            if (r[1] > 1 && r[1] < 10)
                m[r[0]] |= 1<<(r[1]-2);

        for (auto seats : m) {
            bool p1 = !(seats.second & 0b11110000);
            bool p2 = !(seats.second & 0b00111100);
            bool p3 = !(seats.second & 0b00001111);

            if (p1 && p3) continue;
            else if (p1 || p2 || p3) ans -= 1;
            else ans-=2;
        }

        return ans;
    }
};
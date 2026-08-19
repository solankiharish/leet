class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        std::unordered_map<int, int> rowMasks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 1));
            }
        }
        
        int totalGroups = (n - rowMasks.size()) * 2;
        
        int left   = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4); 
        int right  = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8); 
        int middle = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6); 
        
        for (const auto& [row, mask] : rowMasks) {
            bool canLeft   = (mask & left) == 0;
            bool canRight  = (mask & right) == 0;
            bool canMiddle = (mask & middle) == 0;
            
            if (canLeft && canRight) {
                totalGroups += 2;
            } else if (canLeft || canRight) {
                totalGroups += 1;
            } else if (canMiddle) {
                totalGroups += 1;
            }
        }
        
        return totalGroups;
    }
};
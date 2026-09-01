class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size(), start_r, start_c;
        vector<pair<int, int>> litters;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') start_r = r, start_c = c;
                else if (classroom[r][c] == 'L') litter_id[r][c] = litters.size(), litters.push_back({r, c});
            }
        }
        
        int L = litters.size(), target_mask = (1 << L) - 1, moves = 0;
        if (!L) return 0;
        
        vector<vector<vector<int8_t>>> max_e(m, vector<vector<int8_t>>(n, vector<int8_t>(1 << L, -1)));
        queue<array<int, 4>> q;
        q.push({start_r, start_c, 0, energy});
        max_e[start_r][start_c][0] = energy;
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            for (int sz = q.size(); sz > 0; --sz) {
                auto [r, c, mask, e] = q.front(); q.pop();
                if (mask == target_mask) return moves;
                if (e == 0) continue;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') continue;
                    
                    int nmask = mask | (classroom[nr][nc] == 'L' ? (1 << litter_id[nr][nc]) : 0);
                    int ne = (classroom[nr][nc] == 'R') ? energy : e - 1;

                    if (ne > max_e[nr][nc][nmask]) {
                        max_e[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
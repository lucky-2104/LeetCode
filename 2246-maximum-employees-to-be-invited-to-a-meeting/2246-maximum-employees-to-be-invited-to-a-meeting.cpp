#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<bool> visited(n, false);
        int max_cycle = 0;
        vector<pair<int, int>> mutual_pairs;
        vector<int> depth(n, 0);
        unordered_map<int, pair<int, bool>> cycle_info;
        unordered_set<int> cycle_nodes;

        // Step 1: Detect cycles and mutual pairs
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> path;
                int current = i;
                while (true) {
                    if (visited[current]) {
                        auto it = find(path.begin(), path.end(), current);
                        if (it != path.end()) {
                            int idx = it - path.begin();
                            vector<int> cycle(path.begin() + idx, path.end());
                            int cycle_len = cycle.size();
                            bool is_mutual = (cycle_len == 2);
                            for (int node : cycle) {
                                visited[node] = true;
                                cycle_info[node] = {cycle_len, is_mutual};
                                cycle_nodes.insert(node);
                            }
                            if (is_mutual) {
                                mutual_pairs.emplace_back(cycle[0], cycle[1]);
                            } else {
                                max_cycle = max(max_cycle, cycle_len);
                            }
                            for (int j = 0; j < idx; ++j) {
                                visited[path[j]] = true;
                            }
                        }
                        break;
                    }
                    visited[current] = true;
                    path.push_back(current);
                    current = favorite[current];
                }
            }
        }

        // Step 2: Compute depth for mutual pairs
        vector<bool> visited2(n, false);
        for (int u = 0; u < n; ++u) {
            if (cycle_nodes.count(u) || visited2[u]) {
                continue;
            }
            vector<int> path;
            int current = u;
            int entry_node = -1;
            while (true) {
                if (cycle_nodes.count(current)) {
                    entry_node = current;
                    break;
                }
                if (visited2[current]) {
                    if (cycle_info.find(current) != cycle_info.end()) {
                        entry_node = current;
                    } else {
                        entry_node = -1;
                    }
                    break;
                }
                visited2[current] = true;
                path.push_back(current);
                current = favorite[current];
            }
            if (entry_node != -1 && cycle_info.count(entry_node)) {
                auto& info = cycle_info[entry_node];
                if (info.second) { // is_mutual
                    depth[entry_node] = max(depth[entry_node], (int)path.size());
                }
            }
        }

        // Step 3: Calculate mutual sum and return max
        int mutual_sum = 0;
        for (auto& p : mutual_pairs) {
            mutual_sum += 2 + depth[p.first] + depth[p.second];
        }
        return max(max_cycle, mutual_sum);
    }
};
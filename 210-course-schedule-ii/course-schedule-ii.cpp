//
// There are a total of n courses you have to take, labeled from 0 to n - 1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
//
//
// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
//
// 4, [[1,0],[2,0],[3,1],[3,2]]
// There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
//
// Note:
//
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
//
//
//
// click to show more hints.
//
// Hints:
//
// This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
// Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
// Topological sort could also be done via BFS.
//
//


//b[n] - visited
//s[n] - on stack
//g[n] - adjacency list
class Solution {
public:
    vector<int> gsol;
    bool fail=0;
    vector<int> findOrder(int n, vector<pair<int, int>>& p) {
        vector<int> g[n];
        bool b[n],s[n];
        memset(b,0,n);
        for (int i=0; i<p.size(); i++) {
            g[p[i].second].push_back(p[i].first);
        }
        for (int i=0; i<n; i++) {
            if (!b[i]) {
                dfs(i,g,b,s);
            }
        }
        if (fail) {
            return {};
        }
        reverse(gsol.begin(), gsol.end());   
        return gsol;
    }
    void dfs(int v, const vector<int> g[], bool b[], bool s[]) {
        b[v]=1; s[v]=1;
        for (vector<int>::const_iterator it=g[v].begin(); it!=g[v].end(); it++) {
            if (!b[*it]) {
                dfs(*it,g,b,s);
            }
            else if (s[*it]) {
                fail=1;
                return;
            }
        }
        gsol.push_back(v);
        s[v]=0;
        return;
    }
};

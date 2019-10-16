
//Problem


/*There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? */

/*Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.    */



bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int>indegree(numCourses);
        vector<vector<int>>graph(numCourses);
        for(auto p: prerequisites){
            graph[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        for(int i = 0; i < numCourses; i++){
            int j = 0;
            for(; j < numCourses; j++) if(indegree[j] == 0) break;
            if(j == numCourses) return false;
            indegree[j] = -1;
            for(auto x: graph[j]) indegree[x]--;
        }
        return true;
    }

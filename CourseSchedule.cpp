class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false), recursionStack(numCourses, false);

        for(const auto& pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(isCyclic(i, graph, visited, recursionStack)){
                    return false;
                }
            }
        }
        return true;
    }

    bool isCyclic(int course, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recursionStack){
        if(recursionStack[course]){
            return true;
        }
        if(visited[course]){
            return false;
        }
        visited[course] = true;
        recursionStack[course] = true;

        for(int adjCourse:graph[course]){
            if(isCyclic(adjCourse, graph, visited, recursionStack)){
                return true;
            }
        }
        recursionStack[course] = false;
        return false;
    }
};

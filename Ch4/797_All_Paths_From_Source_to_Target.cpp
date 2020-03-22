#include <vector>

std::vector<std::vector<int>> paths;

void DFS(int cur_node, std::vector<std::vector<int>>& graph, std::vector<int> cur_path)
{
    cur_path.push_back(cur_node);
    if(cur_node == graph.size() - 1)
    {
        paths.push_back(cur_path);
        return;
    }

    if(graph[cur_node].empty())
        return;
    
    for(auto adjacent_node : graph[cur_node])
    {
        DFS(adjacent_node, graph, cur_path);
    }
}

std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
    DFS(0, graph, std::vector<int>());
    return paths;
}

int main()
{
    return 0;
}

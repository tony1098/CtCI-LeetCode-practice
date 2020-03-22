#include <vector>
#include <algorithm>
#include <iostream>

enum State
{
    FINISHED,
    VISITING,
    NOT_YET_VISITED
};

struct Node
{
    std::vector<int> adjacent;
    State state = NOT_YET_VISITED;
};

struct Graph
{
    std::vector<Node> nodes;
    Graph(int size) {nodes.resize(size);}
};

class Solution {
public:
    void print(Graph graph)
    {
        for(int i = 0; i < graph.nodes.size(); i++)
        {
            std::cout << "Node " << i << " adjacent nodes: ";
            for(auto adjacent_nodes : graph.nodes[i].adjacent)
            {
                std::cout << adjacent_nodes << " ";
            }
            std::cout << std::endl;
        }
    }

    Graph build_graph(int numCourses, const std::vector< std::vector<int> >& prerequisites)
    {
        Graph graph(numCourses);
        for(auto prereq : prerequisites)
        {
            graph.nodes[prereq[1]].adjacent.push_back(prereq[0]);
        }
        print(graph);
        return graph;
    }

    bool DFS_visit(Graph &graph, int node, std::vector<int> &finishing_times)
    {
        if(graph.nodes[node].state == VISITING)
        {
            // cycle exists
            return false;
        }
        if(graph.nodes[node].state == NOT_YET_VISITED)
        {
            graph.nodes[node].state = VISITING;

            for(auto adjacent_node : graph.nodes[node].adjacent)
            {
                if(!DFS_visit(graph, adjacent_node, finishing_times))
                    return false;
            }
            graph.nodes[node].state = FINISHED;
            finishing_times.push_back(node);
        }
        
        return true;
    }

    std::vector<int> DFS(Graph graph)
    {
        std::vector<int> finishing_times;
        for(int node = 0; node < graph.nodes.size(); node++)
        {
            if(graph.nodes[node].state == NOT_YET_VISITED)
            {
                if (!DFS_visit(graph, node, finishing_times))
                    return std::vector<int>();
            }
        }
        return finishing_times;
    }
    
    std::vector<int> findOrder(int numCourses, std::vector< std::vector<int> >& prerequisites) {
        Graph graph = build_graph(numCourses, prerequisites);
        std::vector<int> finishing_times = DFS(graph);
        std::reverse(finishing_times.begin(), finishing_times.end());
        return finishing_times;
    }
};

int main()
{
    int numCourses = 2;
    std::vector< std::vector<int> > prerequisites;
    prerequisites.push_back(std::vector<int>{0, 1});
    Solution sol;
    std::vector<int> finishing_times = sol.findOrder(numCourses, prerequisites);
    for(auto node : finishing_times)
    {
        std::cout << node << " ";
    }
    return 0;
}



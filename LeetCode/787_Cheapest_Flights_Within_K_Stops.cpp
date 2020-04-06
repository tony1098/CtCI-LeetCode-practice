#include <vector>
#include <algorithm>

int findCheapestPrice(int n, std::vector< std::vector<int> >& flights, int src, int dst, int K) {
    std::vector<int> dist(n, 1e8);
    dist[src] = 0;

    for(int k = 1; k <= K + 1; k++) 
    {
        std::vector<int> copy(dist);
        for(auto e : flights)
        {
            copy[e[1]] = std::min(copy[e[1]], dist[e[0]] + e[2]);
        }
        dist = copy;
    }
    return dist[dst] == 1e8 ? -1 : dist[dst];
}

int main()
{

}
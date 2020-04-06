#include <vector>
#include <string>

int minDistance(string word1, string word2) {
    std::vector< std::vector<int> > minDist(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
    for(int i = 0; i <= word1.size(); i++)
        minDist[i][0] = i;
    for(int j = 0; j <= word2.size(); j++)
        minDist[0][j] = j;
    for(int i = 1; i <= word1.size(); i++)
    {
        for(int j = 1; j <= word2.size(); j++)
        {
            if(word1[i - 1] == word2[j - 1])
                minDist[i][j] = minDist[i - 1][j - 1];
            else
                minDist[i][j] = 1 + std::min(std::min(minDist[i - 1][j - 1], minDist[i - 1][j]), minDist[i][j - 1]);
        }
    }
    return minDist[word1.size()][word2.size()];
}
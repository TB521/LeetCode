#include "include.hpp"
using namespace std;
/*
785. 判断二分图
给定一个无向图graph，当这个图为二分图时返回true。

如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。

graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。


示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释: 
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。

示例 2:
输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
输出: false
解释: 
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。
注意:

graph 的长度范围为 [1, 100]。
graph[i] 中的元素的范围为 [0, graph.length - 1]。
graph[i] 不会包含 i 或者有重复的值。
图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。
通过次数10,375提交次数22,110
在真实的面试中遇到过这道题？
*/

/*染色 + 层次遍历*/
class Solution {
public:
    //图的点的结构
    struct Node
    {
        int index;
        int color = 0;
        vector<int> next;
        Node(int index,int color = 0):index(index),color(color){}
    };

    /*主*/
    bool isBipartite(vector<vector<int>>& graph) {
        vector<Node> m;
        /*边转向量表*/
        for(int i = 0;i<graph.size();i++)
            m.push_back(Node(i));
        for(int i =0;i<graph.size();i++)
        {
            m[i].next = graph[i];
        }
        //是否已经访问
        vector<bool> isVisited(graph.size(),false);
        //层次遍历队列
        queue<Node> q;
        //去独立的点和
        for(int i = 0;i<graph.size();i++)
        {
            if(m[i].next.size() == 0) continue;
            if(isVisited[i]) continue;
            
            m[i].color = 1;
            q.push(m[i]);
            while(q.size() > 0)
            {
                Node node = q.front();
                q.pop();
                if(isVisited[node.index]) continue;
                //cout<<node.index<<":"<<node.color<<";";
                for(int index:node.next)
                {
                    if(m[index].color == 0) m[index].color = -node.color;
                    if(m[index].color == node.color) return false;
                    q.push(m[index]);
                }
                isVisited[node.index] = true;
            }
        }
        return true;
    }
};
/*LeetCode 官方广度优先搜索*/
class Solution {
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    vector<int> color;

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, UNCOLORED);
        for (int i = 0; i < n; ++i) {
            if (color[i] == UNCOLORED) {
                queue<int> q;
                q.push(i);
                color[i] = RED;
                while (!q.empty()) {
                    int node = q.front();
                    int cNei = (color[node] == RED ? GREEN : RED);
                    q.pop();
                    for (int neighbor: graph[node]) {
                        if (color[neighbor] == UNCOLORED) {
                            q.push(neighbor);
                            color[neighbor] = cNei;
                        }
                        else if (color[neighbor] != cNei) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    system("pause");
};
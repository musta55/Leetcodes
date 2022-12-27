#include<iostream>
#include<queue>
#define NODE 6
using namespace std;
 class node {
     public:
    int val;
    int state;      // 0 for unvisited, 1 for visited, 2 for complete
};

int graph[NODE][NODE] = {
    {0, 1, 1, 1, 0, 0},
   {1, 0, 0, 1, 1, 0},
   {1, 0, 0, 1, 0, 1},
   {1, 1, 1, 0, 1, 1},
   {0, 1, 0, 1, 0, 1},
   {0, 0, 1, 1, 1, 0}
};

void bfs (node *vert,node s)
{
    node u;
    int i,j;
    queue <node> que;
    for(int i=0;i<NODE;i++) vert[i].state = 0;  //Not visited
    
    vert[s.val].state = 1;      //visited
    que.push(s);        //inserting starting node
    
    while(!que.empty())
    {
        u =que.front();
        que.pop();
        cout << char(u.val + 'A') << " ";
        for(i=0;i<NODE;i++)
        {
            if(graph[i][u.val])
            {
                if(vert[i].state == 0)
                {
                    vert[i].state = 1;
                    que.push(vert[i]);
                }
            }
        }
        u.state = 2;
    }
            
    
}

int main(){
    node vertices[NODE];
    node start;
    char s;
    for(int i=0;i<NODE;i++)
    {
        vertices[i].val = i; 
    }
    
    s = 'B';
    start.val = s- 'A';
    
    cout << "BFS Traversal: ";
    bfs(vertices, start);
    cout << endl;
    
    return  0;
}
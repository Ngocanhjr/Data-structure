#include <iostream>

using namespace std;

void BFS(int u)
{
    // Step 1: init
    queue = 0;          // create empty queue
    push(queue, u);     // push u into queue
    visited[u] = true;  // marked u is visted
    // Step 2: loop when queue not empty
    while (queue != ∅)
    {
        v.queue.front();  // Take out the vertex at the beginning of the queue
        queue.pop;        // Erase vertex from queue
        <Visted vertex v>
            // Browse vertices adjacent to v that have not been visited and push them in the queue
            for (int x : adj[v])
        {
            if (!visted[x])
            {
                push(queue, x);
                visited[x] = true;
            }
        }
    }
}
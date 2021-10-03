// C++ Code implementation for above problem
#include <iostream>
#include <queue>
#include<fstream>
using namespace std;


// QItem for current location and distance
// from source location
class QItem {
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w) : row(x), col(y), dist(w)
    {
    }
};

void makeBarriers(int **grid,int R,int C) {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == 3) {

                if (i - 1 >= 0) {   //up
                    if(grid[i - 1][j] != 2 && grid[i - 1][j] != 1)
                        grid[i - 1][j] = 4;
                }
            
                if (i + 1 < R) {  
                    if (grid[i + 1][j] != 2 && grid[i + 1][j] != 1)//down
                        grid[i + 1][j] = 4;
                }


                if (j - 1 >= 0) {  
                    if (grid[i][j - 1] != 2 && grid[i][j - 1] != 1)//left
                        grid[i][j - 1] = 4;
                }


                if (j + 1 < C) {  
                    if (grid[i][j + 1] != 2 && grid[i][j + 1] != 1)//right
                        grid[i][j + 1] = 4;
                }

                if (i - 1 >= 0 && j - 1 >= 0) { 
                    if (grid[i - 1][j - 1] != 2 && grid[i - 1][j - 1] != 1)//top left
                        grid[i - 1][j - 1] = 4;
                }

                if (i - 1 >= 0 && j + 1 < C) { //top right
                    if (grid[i - 1][j + 1] != 2 && grid[i - 1][j + 1] != 1)
                        grid[i - 1][j + 1] = 4;
                }

                if (i + 1 < R && j - 1 >= 0) { //bottom left
                    if (grid[i + 1][j - 1] != 2 && grid[i + 1][j - 1] != 1)
                        grid[i + 1][j - 1] = 4;
                }

                if (i + 1 < R && j + 1 < C) { //bottom right
                    if (grid[i + 1][j + 1] != 2 && grid[i + 1][j + 1] != 1)
                        grid[i + 1][j + 1] = 4;
                }
            }
        }
    }

}


int minDistance(int **grid,int R,int C)
{
    makeBarriers(grid,R,C);
    
    QItem source(0, 0, 0);

    // To keep track of visited QItems. Marking
    // blocked cells as visited.

    bool** visited = new bool* [R];
    for (int i = 0; i < R; i++) {
        visited[i] = new bool[C];
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == 0 || grid[i][j] == 2)
                visited[i][j] = false;
            else 
                visited[i][j] = true;

            // Finding source
            if (grid[i][j] == 1)
            {
                source.row = i;
                source.col = j;
            }
        }
    }

    // applying BFS on matrix cells starting from source
    queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
    
    while (!q.empty()) {
    
        QItem p = q.front();
        q.pop();

        int row = p.row;
        int col = p.col;
        // Destination found

        if (grid[p.row][p.col] == 2)
            return p.dist;
        // moving up
        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false) {
            q.push(QItem(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }

        // moving down
        if (p.row + 1 < R && visited[p.row + 1][p.col] == false) {
            q.push(QItem(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }

        // moving left
        if (p.col - 1 >= 0 && visited[p.row][p.col - 1] == false) {
            q.push(QItem(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }

        // moving right
        if (p.col + 1 < C && visited[p.row][p.col + 1] == false) {
            q.push(QItem(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}


// Driver code
int main()
{
    fstream f("F.txt");
    int N;
    f >> N;
    while (N--) {
        int R, C;
        f >> R >> C;
        int** grid = new int* [R];
        for (int i = 0; i < R; i++) {
            grid[i] = new int[C];
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                f >> grid[i][j];
            }
        }

        cout << minDistance(grid,R,C);
    
    }
   
    return 0;
}
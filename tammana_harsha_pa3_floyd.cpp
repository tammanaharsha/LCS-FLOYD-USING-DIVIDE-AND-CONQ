#include <bits/stdc++.h>

//defining the random number generation within MAX and MIN values
#define GEN_RAND_NUM ((rand() % (MAX - MIN + 1)) + MIN)

using namespace std;

// Assigns randomly generated number to the adjacency matrix of the graph
void rand_gen_graph(int n,vector<vector<int>> &graph){
    int MAX = 10, MIN=1;                // max and min values of the weights
    for (int row = 0; row < n; row++)
    {
        int col=0;
        while (col < row)
        {
            int val = GEN_RAND_NUM;     //generates the random number
            if (row != col)             //Value at i==j will be 0
            {
                graph[row][col] = val;  
                graph[col][row] = val;  //allocats both for [i][j] and [j][i] since it is undirected graph
            }
            col++;
        }
    }
}

//Displays the graph in the adjacency matrix format
void display_adj_matrix(int n,vector<vector<int>>& adj_matrix){
    cout << "**********Adjacency Matrix of Graph**********"<<endl<<endl;
    for(int i=0;i<n;i++){
        cout << "\t" << i + 1;
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "*********";
    }
    cout<<endl;
    for (int row = 0; row < n; row++)
    {
        for(int col=0;col<n;col++){
            if(col==0){
                cout << row + 1 << "  |\t";
            }
            cout << adj_matrix[row][col] << "\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

// Prints the shortest path from x to y
void print_path(vector<vector<int>> &next_node,int x, int y){
    cout << "V" << x + 1 << " ";
    if(next_node[x][y]==-1) {
        cout << "V" << y + 1 << " ";
        return;
    }


    cout<<"V"<<x+1<<" ";
    while(x!=y){
        x = next_node[x][y];
        if(x!=y)
            cout<<"V"<<x+1<<" ";
        else
            cout<<"V"<< x+1 ;
    }
}

void print_Pmatrix(vector<vector<int>> next_node, int n){
    cout<<"Pmatrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<next_node[i][j]+1<<" ";
        }
        cout<<endl;
    }
    cout << endl;
}

void print_Amatrix(vector<vector<int>> min_cost, int n)
{
    cout << "Amatrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << min_cost[i][j]<< " ";
        }
        cout << endl;
    }
    cout<<endl;
}

// Floyds algorithm is implemented to find the shortest paths between two points
void compute_paths(int n, vector<vector<int>> &adj_matrix)
{
    vector<vector<int>> min_cost = adj_matrix;              // carries the shortest length of path
    vector<vector<int>> next_node(n, vector<int>(n, -1));   // carries the next node in the shortest path

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j)
                next_node[i][j] = j;
        }
    }


    for (int k = 0; k < n; k++)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                int min_val;

                if ((min_cost[i][k] + min_cost[k][j]) < min_cost[i][j]){    //verifies the condition that is i to j is minimum of i to k + k to j
                    min_val = min_cost[i][k] + min_cost[k][j];
                    next_node[i][j] = next_node[i][k];
                }
                else{
                    min_val = min_cost[i][j];
                }
                min_cost[i][j] = min_val;
            }
        }
    }

    print_Amatrix(min_cost, n);
    print_Pmatrix(next_node,n);

    for(int i=0;i<n;i++){
        cout<<"V"<<i+1<<"-Vj : Shortest path and length"<<endl;
        for(int j=0;j<n;j++){
            print_path(next_node, i, j);
            cout<< ": " << min_cost[i][j] << endl;
        }
        cout<<endl;
    }
}

// Function declares the graph and genrates it and finds the shortest paths
void floyds_algo(int n)
{
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));

    rand_gen_graph(n, adj_matrix);
    
    //display_adj_matrix(n, adj_matrix);

    compute_paths(n, adj_matrix);
}

// n gets initialized with random number and a graph is generate randomly with n nodes
int main(){
    srand(time(0));
    int MAX = 10,MIN = 5;
    int n = GEN_RAND_NUM;

    cout<<"Selected n value : "<<n<<endl<<endl;

    floyds_algo(n);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 3300;
const int INF = INT_MAX;

int n;
int graph[NMAX][NMAX];
pair<int, int> dist[NMAX];
vector<pair<int, int> > tree[NMAX];
float x_[NMAX], y_[NMAX];
int vis[NMAX];
vector<int> order;

string buildFileName(int num){
    string fileName = "ent";
    if(num < 10){
        fileName += "0";
    }
    fileName += to_string(num);
    fileName += ".txt";
    return fileName;
}

int nint(float distance){
    return (int) (distance + 0.5);
}

void readAndBuildGraph(string &fileName){
    int id;
    float readx, ready;
    int read = 0;
    FILE* file = fopen(fileName.c_str(), "r");
    fscanf(file, "%d", &n);
    order.clear();
    for(int i = 0; i <= n; i++){
        tree[i].clear();
        dist[i] = make_pair(INF, -1);
        vis[i] = 0;
    }
    while(read++ < n){
        fscanf(file, "%d %f %f", &id, &readx, &ready);
        x_[id] = readx;
        y_[id] = ready;
    }
    fclose(file);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) if(i != j) {
            float xd = x_[i] - x_[j];
            float yd = y_[i] - y_[j];
            int dij = nint( sqrt(xd * xd + yd * yd) );
            graph[i][j] = dij;
            graph[j][i] = dij;
        }else{
            graph[i][i] = 0;
        }
    }
}

//finding minimum vertex
pair<int, int> findMin(){
    int nodeToJoinMst = -1;
    int bestDist = INF;
    int nodeFromMst = INF;//node from mst

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(dist[i].first < bestDist){//getting the node with lowest distance from mst
                nodeToJoinMst = i;
                bestDist = dist[i].first;
                nodeFromMst = dist[i].second;
            }else if(dist[i].first == bestDist){
                if(dist[i].second < nodeFromMst){//in case of tie, getting the lowest index from mst
                    nodeToJoinMst = i;
                    nodeFromMst = dist[i].second;
                }else if(dist[i].second == nodeFromMst){
                    //in case of tie again, we have already got the lowest index
                }
            }
        }
    }
    return make_pair(nodeToJoinMst, nodeFromMst);
}

//running prim algorithm
void prim(){
    dist[1] = make_pair(0, -1);//first = distance from mst; second = who node came from
    for(int i = 1; i <= n; i++){
        pair<int, int> best = findMin();
        int newNode = best.first;//new node to join mst
        int treeNode = best.second;//node from mst that links newNode
        vis[newNode] = 1;
        if(dist[newNode].second != -1){//building the tree
            tree[newNode].push_back(make_pair(graph[newNode][treeNode], treeNode));
            tree[treeNode].push_back(make_pair(graph[treeNode][newNode], newNode));
        }
        for(int v = 1; v <= n; v++){//updating neighbors
            if(!vis[v] && graph[newNode][v] < dist[v].first){
                dist[v] = make_pair(graph[newNode][v], newNode);
            }else if(!vis[v] && graph[newNode][v] == dist[v].first && newNode < dist[v].second){
                dist[v] = make_pair(graph[newNode][v], newNode);
            }
        }
    }
}

//doing preorder
void preOrder(int root, int parent){
    //sorting by distance, and if have a tie, by lowest index
    //sort(tree[root].begin(), tree[root].end());
    order.push_back(root);
    for(int i = 0; i < tree[root].size(); i++){
        int child = tree[root][i].second;
        if(child != parent){
            preOrder(child, root);
        }
    }
}

int main(){
    srand(time(NULL));
    int m;
    scanf("%d", &m);
    FILE *out = fopen("saida1.txt", "w");
    for(int test = 1; test <= m; test++){
        string fileName = buildFileName(test);
        readAndBuildGraph(fileName);
        prim();
        preOrder(1, 1);

        //obtaining cost of cycle C
        int ans = 0;
        for(int i = 0; i < order.size(); i++){
            int u = order[i];
            int v = order[(i + 1) % order.size()];
            ans += graph[u][v];
        }
        fprintf(out, "%d\n", (n == 0) ? 0 : ans);
    }
    fclose(out);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int NMAX = 3300;
const int INF = INT_MAX/3;

int n;
int graph[NMAX][NMAX];
vector<pair<int, int> > tree[NMAX];
float x_[NMAX], y_[NMAX];
int vis[NMAX];
vector<int> order;

string buildFileName(int num){
    string fileName = "ent";
    if(num < 10){
        fileName += "0";
    }
    fileName += std::to_string(num);
    fileName += ".txt";
    return fileName;
}

/**
 * Isso deveria usar float mesmo ?
 */
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

void generateMinimumSpanningTree() {
    vis[1] = true;
    // distance, node in-tree, node out-tree
    priority_queue<pair<int, pair<int, int> > > prim_heap;

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        prim_heap.push(make_pair(-graph[1][i], make_pair(-1, -i)));
    }

    while (!prim_heap.empty()) {
        while (!prim_heap.empty() && vis[-prim_heap.top().second.second]) {
            prim_heap.pop();
        }

        int dist_to_tree = -prim_heap.top().first;
        int node_in_tree = -prim_heap.top().second.first;
        int node_out_tree = -prim_heap.top().second.second;

        vis[node_out_tree] = true;

        tree[node_in_tree].push_back(make_pair(dist_to_tree, node_out_tree));
        tree[node_out_tree].push_back(make_pair(dist_to_tree, node_in_tree));

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            prim_heap.push(make_pair(-graph[node_out_tree][i], make_pair(-node_out_tree, -i)));
        }
    }
}

void preOrder(int root, int parent){
    //sorting by distance, and if have a tie, by lowest index
    sort(tree[root].begin(), tree[root].end());
    order.push_back(root);
    for(int i = 0; i < tree[root].size(); i++){
        int child = tree[root][i].second;
        if(child != parent){
            preOrder(child, root);
        }
    }
}

int main() {
    int m;
    scanf("%d", &m);
     FILE *out = fopen("saida3.txt", "w");
    for(int test = 1; test <= m; test++){
        string fileName = buildFileName(test);
        readAndBuildGraph(fileName);
        generateMinimumSpanningTree();
        preOrder(1, 1);
        int ans = 0;
        for(int i = 0; i < order.size(); i++){
            ans += graph[order[i]][order[(i + 1) % order.size()]];
        }
        fprintf(out, "%d\n", (n == 0) ? 0 : ans);
    }
    fclose(out);
    return 0;
}

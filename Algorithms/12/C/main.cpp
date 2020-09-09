#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct edge {
	int to;
    int from;
    int cap;
    int flow;
    int pos;
    int other;
    
    edge(int pos, int to, int from, int cap, bool real) : to(to), from(from), cap(cap), flow(0), pos(pos), other(-1) {}    
};

struct vertex {
	edge * parent = nullptr;
    bool visited = false;
    int dist = 0;
    int real_ptr = 0;
    int rev_ptr = 0;
    vector<edge> real;
    vector<edge> rev;
};

vector<vertex> verts;

int bfs() {
    for (vertex &v : verts) {
    	v.visited = false;
        v.dist = INT_MAX;
    }
    verts[0].dist = 0;
    verts[0].visited = true;
    queue<vertex *> q;
    q.push(&verts[0]);
    while (!q.empty()) {
        vertex *v = q.front();
        q.pop();
        for (edge &e : v->rev) {
            if (e.cap - e.flow == 0 || verts[e.to].visited) continue;
            verts[e.to].dist = v->dist + 1;
            verts[e.to].visited = true;
            q.push(&verts[e.to]);
        }
        for (edge &e : v->real) {
            if (e.cap - e.flow == 0 || verts[e.to].visited) continue;
            verts[e.to].dist = v->dist + 1;
            verts[e.to].visited = true;
            q.push(&verts[e.to]);
        }
 
    }
    return verts[n - 1].visited;
}

int dfs(int v, int c) {
    if (v == (verts.size() - 1) || c == 0) return c;
    vertex &vert = verts[v];
    for (; vert.rev_ptr < vert.rev.size(); ++vert.rev_ptr) {
        edge &e = vert.rev[vert.rev_ptr];
        if (e.cap - e.flow == 0) continue;
        if (verts[e.to].dist == vert.dist + 1) {
            int flow = dfs(e.to, min(e.cap - e.flow, c));
            if (flow > 0) {
                e.flow += flow;
                verts[e.to].real[e.other].flow -= flow;
                return flow;
            }
        }
    }
    for (; vert.real_ptr < vert.real.size(); ++vert.real_ptr) {
        edge &e = vert.real[vert.real_ptr];
        if (e.cap - e.flow == 0) continue;
        if (verts[e.to].dist == vert.dist + 1) {
            int flow = dfs(e.to, min(e.cap - e.flow, c));
            if (flow > 0) {
                e.flow += flow;
                verts[e.to].rev[e.other].flow -= flow;
                return flow;
            }
        }
    }
    return 0;
}

void maxflow() {
    while (bfs()) {
        for (vertex &v : verts) {
            v.real_ptr = 0;
            v.rev_ptr = 0;
        }
        int flow = 1;
        while (flow > 0) {
            flow = dfs(0, INT_MAX);
        }
    }
}

struct path {
    int flow;
    int length;
    vector<int> edges;
    
    path() : length(0), flow() {}
};

vector<path> paths;

int find() {
    for (vertex &v : verts) v.visited = false;
    int pos = 0;
    edge *next = nullptr;
    int flow = INT_MAX;
    while (true) {
        for (edge &e : verts[pos].real) {
            if (e.flow) {
                next = &e;
                break;
            } 
			else next = nullptr;
        }
        if (next == nullptr) return 0;
        if (flow > next->flow) flow = next->flow;
        verts[next->to].visited = true;
        verts[next->to].parent = next;
        pos = next->to;
        if (pos == n - 1) break;
    }
    return flow;
}

int decomposition() {
    for (vertex &v : verts) v.parent = nullptr;
    while (true) {
        int flow = find();
        if (!flow) return paths.size();
        paths.emplace_back();
        paths.back().flow = flow;
        edge *e = verts[n - 1].parent;
        while (e != nullptr) {
            paths.back().edges.push_back(e->pos);
            paths.back().length += 1;
            e->flow -= flow;
            e = verts[e->from].parent;
        }
    }
}

int main() {
	freopen("decomposition.in", "r", stdin);
    freopen("decomposition.out", "w", stdout);
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);
    cin >> n >> m;
    verts.resize(n);
    for (int i = 0; i < m; ++i) {
   		int from, to, cap;
        cin >> from >> to >> cap;
        from--;
        to--;
        verts[from].real.emplace_back(i, to, from, cap, true);
        verts[to].rev.emplace_back(i, from, to, 0, false);
        verts[to].rev.back().other = verts[from].real.size() - 1;
        verts[from].real.back().other = verts[to].rev.size() - 1;
    }
    maxflow();
    int answer = decomposition();
    cout << answer << endl;
    for (int i = 0; i < answer; ++i) {
        cout << paths[i].flow << " " << paths[i].length << " ";
        for (int j = paths[i].length - 1; j >= 0; j--) cout << paths[i].edges[j] + 1 << " ";
        cout << endl;
    }
	return 0;
}

#include <cstdio>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

static const int INF = 0x3f3f3f3f;

struct Node {
    bool isRetailer;
    int amount;
    vector<int> supply;

    Node()
        : isRetailer(false),
        amount(0)  {
    }
};

// 内存超出
void matrix() {
    int n;
    double p, r;
    cin >> n >> p >> r;
    // if graph[i][i] != INF, is a retailer
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        int ki;
        cin >> ki;
        if (ki == 0) {
            int amount;
            cin >> amount;
            graph[i][i] = amount;
        } else {
            // receiver可以从supplier i拿货
            for (int j = 0; j < ki; ++j) {
                int receiver;
                cin >> receiver;
                graph[receiver][i] = 1;
            }
        }
    }
    function<double(int)> track = [&] (int index) {
        for (int i = 0; i < graph.size(); ++i) {
            if (i != index && graph[index][i] != INF)  {
                auto price = track(i);
                return price * r / 100. + price;
            }
        }
        return p;
    };
    double total = 0.;
    for (int i = 0; i < n; ++i) {
        // is retailer
        if (graph[i][i] != INF) {
            total += track(i) * graph[i][i];
        }
    }
    printf("%.1f\n", total);
}

int main() {
    int n;
    double p, r;
    cin >> n >> p >> r;
    // if graph[i][i] != INF, is a retailer
    vector<Node> holder(n);
    for (auto& node: holder) {
        int ki;
        cin >> ki;
        if (ki == 0) {
            cin >> node.amount;
            node.isRetailer = true;
        } else {
            node.supply = vector<int>(ki);
            for (auto& receiver: node.supply) {
                cin >> receiver;
            }
        }
    }
    double total = 0.;
    // @param double price，代表下一个进货商将会以这个价格出售
    function<void(int, double)> dfs = [&] (int index, double price) {
        if (holder[index].isRetailer) {
            total += price *  (double)(holder[index].amount);
            return;
        }
        for (auto receiver: holder[index].supply) {
            dfs(receiver, price * (r / 100. + 1.));
        }
    };
    dfs(0, p);
    printf("%.1f\n", total);
}
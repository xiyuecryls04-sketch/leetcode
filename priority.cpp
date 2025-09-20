#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    priority_queue<int> pq; // 默认是最大堆
    pq.push(10);
    pq.push(5);
    pq.push(20);

    while (!pq.empty()) {
        cout << pq.top() << " "; // 输出最大值
        pq.pop();
    }
}

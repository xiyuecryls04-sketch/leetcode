#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

// 定义最大可能的节点数或层级数
// 可以根据问题的具体约束进行调整
const int MAXN = 100005;

// 'deep' 是一个向量数组，deep[i] 存储了第 i 层的所有元素
std::vector<long long> deep[MAXN];

int main() {

    int n,x; // 当前测试用例的输入项数量
    
    // 循环处理多组测试用例
    while (std::cin >> n) {
        // 清空 'deep' 数组，为新的测试用例做准备
        for (int i = 0; i < n; i++) {
            deep[i].clear();
        }
        int maxd = 0;

        // 读取 n 个节点的深度，并更新最大深度
        for (int i = 0; i < n; i++) {
            int x; // 当前项的深度
            std::cin >> x;
            // 在深度为 x 的向量中添加一个占位符，这里为 0
            deep[x].push_back(0);
            maxd = std::max(maxd,x);
        }

        // 根据原代码逻辑，将最深一层的所有元素设置为 1
        // 注意：原代码的循环逻辑 'if (deep[i][j])' 会导致这个赋值不成功
        // 这里我们直接将最深层的所有元素设置为 1
        long long temp = 1;
        

        // 从最深层向上遍历，计算父节点的值
        for (int i = maxd; i > 0; i--) {
            // 对当前层的节点值进行排序
            
            // 将相邻的两个节点值相加，并将结果添加到上一层
            for (size_t j = 0; j< deep[i].size(); j ++) {
                if(!deep[i][j])
                    deep[i][j]=temp;
            }
            std::sort(deep[i].begin(), deep[i].end());

            for(int j = 0;j<deep[i].size();j+=2){
                deep[i - 1].push_back(deep[i][j] + deep[i][j + 1]);

            }

            temp = *(deep[i].end()-1);

           
        }

        // 输出根节点 (第 0 层) 的值
        if (!deep[0].empty()) {
            std::cout << deep[0][0] << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}
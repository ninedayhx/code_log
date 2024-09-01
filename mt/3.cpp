// tag: set
// 题目说明：1.输入n表示工人数量，输入k表示希望种这么多树
//         2.输入一行n个数字，表示每个工人的位置
//         工人会从自己的位置开始，往后种x颗树，种的树可以重叠，
//         问x的最小值为多少，能够使工人至少种k颗树
//         eg: input: 3 6
//                    1 2 5
//            output: 3
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    // 工人的位置
    vector<int> person_pos(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        person_pos[i] = x;
    }
    // 插入了多少树，set的size表示了树的量是否足够
    unordered_set<int> tree_pos;
    // 工人种树的长度，从1往前找
    int len = 0;
    // 插入树,更新len以后，无需每次都从1开始插入一遍，
    // 直接继承之前的就行
    for (len = 0; tree_pos.size() < k; len++)
    {
        for (auto &i : person_pos)
        {
            tree_pos.insert(i + len);
        }
    }
    cout << len << endl;
}
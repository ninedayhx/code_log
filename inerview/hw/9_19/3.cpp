#include <bits/stdc++.h>

using namespace std;

struct process_t
{
    vector<pair<int, int>> files;
};

int main()
{
    int N, M, C;
    cin >> N >> M >> C;
    vector<process_t> process(N);
    for (int i = 0; i < M * N; ++i)
    {
        int id, size, num;
        cin >> id >> size >> num;
        process[id].files.emplace_back(size, num);
    }
    vector<vector<int>> dp(N, vector<int>(C, 0));
}
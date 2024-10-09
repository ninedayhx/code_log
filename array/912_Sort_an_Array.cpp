// tag: array quick_sort 快速排序 归并排序 冒泡排序
#include <bits/stdc++.h>

using namespace std;

// 排序算法汇总
/**
 * @brief 冒泡排序
 * * 时间复杂度 O(n^2)
 * * 空间复杂度 O(1)
 * @param arr
 */
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

/**
 * @brief 没有优化的快速排序,每次都将区间中最右边元素作为基准
 * @param nums
 * @param l
 * @param r
 */
void quickSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        // 以最右边的元素作为比较基准
        int base = arr[r];
        // i是用于交换的索引
        int i = l;
        // 遍历当前区间中，除基准以外的所有元素，
        // 把小于等于基准的元素，放在i位置
        // 遍历结束以后，将分为两个区间
        // l-i-1的位置的数字都将小于等于base
        // i-r-1位置的数字 都将大于base
        // r 位置即是base自身
        for (int j = l; j < r; ++j)
        {
            if (arr[j] <= base)
            {
                swap(arr[i++], arr[j]);
            }
        }
        // 将base 作为分割，放到两个区间的中间，
        // 这样l~i-1将小于等于base
        // i = base
        // i+2~r 大于base
        swap(arr[i], arr[r]);
        // 记录分割的位置为part，part等于分割线
        int part = i;
        // 分别对左右区间继续进行分割，直到左右区间l>=r 迭代停止，排序完成
        quickSort(arr, l, part - 1);
        quickSort(arr, part + 1, r);
    }
}

/**
 * @brief 通过随机选取基准进行快排优化,随机选一个数，然后把这个数排到区间最后，然后再像正常
 * 快排一样处理，仍然会超时
 * @param arr
 * @param l
 * @param r
 */
void quickSort_random(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        // 随机选取基准
        int base_idx = l + rand() % (r - l + 1);
        swap(arr[base_idx], arr[r]);
        int base = arr[r];
        int i = l;
        for (int j = l; j < r; ++j)
        {
            if (arr[j] <= base)
            {
                swap(arr[j], arr[i++]);
            }
        }
        swap(arr[i], arr[r]);
        int part = i;
        quickSort_random(arr, l, part - 1);
        quickSort_random(arr, part + 1, r);
    }
}

/**
 * @brief 优化版的随机快排，随机选取元素以后，不再把这个元素放在最后，而是原地划分左右区间
 * 通过三路比较，进行原地随机快排
 * * 时间复杂度 O(n*logn)
 * * 空间复杂度 O(logn)
 * @param arr
 * @param l
 * @param r
 */
void quickSort_random_op(vector<int> &arr, int l, int r)
{
    // 随机原地分区
    auto part = [&](auto &&part, int x) -> int
    {
        int first = l; // 指向最新的需要替换的左区间坐标
        int last = r;  // 指向最新的需要替换的右区间坐标
        int p = l;     // 用于遍历的指针
        // 遍历当前区间
        while (p <= last)
        {
            if (arr[p] == x)
            { // 等于x不变
                ++p;
            }
            else if (arr[p] < x)
            { // 小于x放左边 // 左边都是已经比较过的，不会遗漏，所以p++
                swap(arr[p++], arr[first++]);
            }
            if (arr[p] > x)
            { // 大于x放右边， 被交换过来的没有被比较过，所以p不加，继续参与下一轮比较
                swap(arr[p], arr[last--]);
            }
            // 最后x的位置就是fisrt或者last
        }
        return first;
    };
    if (l < r)
    {
        // 随机选取基准;
        int part_idx = part(part, arr[l + rand() % (r - l + 1)]);
        quickSort_random(arr, l, part_idx - 1);
        quickSort_random(arr, part_idx + 1, r);
    }
}

/**
 * @brief 归并排序
 * @param arr
 * @param l
 * @param r
 */
void mergeSort(vector<int> &arr, int l, int r)
{
}

vector<int> sortArray(vector<int> &nums)
{
}

int main()
{
    vector<int> nums;
    while (1)
    {
        int x;
        cin >> x;
        nums.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }
    auto nums1 = nums, nums2 = nums, nums3 = nums;
    bubbleSort(nums1);
    quickSort(nums2, 0, nums2.size() - 1);
    for (auto &i : nums1)
    {
        cout << i << ' ';
    }
    cout << endl;
    for (auto &i : nums2)
    {
        cout << i << ' ';
    }
    cout << endl;
}
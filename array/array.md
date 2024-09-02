# 数组题
## 二分查找
二分查找可以分为找区间和找对应值
都需要使用左闭右闭的形式
- 找目标值,**找目标值在c++库中有对应api为binary_search(n.begin(), n.end(), target)**
    ```cpp
    int l = 0, r = n-1;
    while(l<=r){
        int m = (l+r)>>1;
        if(num[m]==target) return;
        if(num[m] >target) r = m-1;
        if(num[m] <target) l = m+1; 
    }
    ```
- 找不小于目标的第一个值，也就是找区间，找target处于数组中的最小区间的右值
    ```cpp
    int l = 0, r = n-1;
    int ans = n;
    while(l<=r){
        int m = (l+r)>>1;
        if(target <= num[m]){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return ans;
    ```
    上面，如果返回ans = n说明目标值比数组中所有的值都大
- 找不大于目标的最后一个值，也就是找target处于数组中的最小区间的左值
    ```cpp
    int l = 0,r = n-1;
    int ans = -1;
    while(l<=r){
        int m = (l+r)>>1;
        if(target>=num[m]){
            ans = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }
    return ans;
    ```
    上面如果返回ans = -1说明target比数组中所有的值都要小

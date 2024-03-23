/**
* leetcode 88 合并两个有序数组 暴力解法
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int tmp=0,cnt=0;
	nums1.insert(nums1.begin()+m,nums2.begin(),nums2.end());
	for(int i=0; i<n+m-1; i++)
	{
		for(int j=0;j<n+m-1-i;j++)
		if(nums1.at(j)>nums1.at(j+1))
		{
			tmp = nums1.at(j);
			nums1.at(j) = nums1.at(j+1);
			nums1.at(j+1) = tmp;
		}
	}
}


int main()
{

	vector<int> n1 = {1,2,3,0,0,0},n2={4,5,6};
	int n=3,m=3;
	merge(n1,m,n2,n);
	for(int k=0;k<n+m;k++)
	{
		cout<<n1.at(k)<<endl;
	}

	return 0;
};
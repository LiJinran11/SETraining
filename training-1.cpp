//最大子串和
#include<stdio.h>

int MaxSubArray(int* A, int n)
{
    int maxSum = A[0];//全负情况，返回最大负数
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
     for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                currSum += A[k];
            }
            if (currSum > maxSum)
             maxSum = currSum;

currSum = 0; //这里要记得清零，否则的话sum最终存放的是所有子数组的和。
        }
    }
    return maxSum;
}

int main()
{
    int a[20],n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("最大字串和为:%d",MaxSubArray(a,n));
    return 0;
}
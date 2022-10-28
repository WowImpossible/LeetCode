#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//函数作用：为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。
//如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
//如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
//如果 k == 0 ，将第 i 个数字用 0 替换。
//由于 code 是循环的， code[n - 1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n - 1]

//输入：code = [5,7,1,4], k = 3>0
//输出：[12, 10, 16, 13]
//解释：每个数字都被接下来 3 个数字之和替换。解密后的密码为[7 + 1 + 4, 1 + 4 + 5, 4 + 5 + 7, 5 + 7 + 1]。注意到数组是循环连接的。

//示例 2：
//输入：code = [1, 2, 3, 4], k = 0
//输出：[0, 0, 0, 0]
//解释：当 k 为 0 时，所有数字都被 0 替换。

//示例 3：
//输入：code = [2, 4, 9, 3], k = -2
//输出：[12, 5, 6, 13]
//解释：解密后的密码为[3 + 9, 2 + 3, 4 + 2, 9 + 4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 之前 的数字。

//传入参数的定义：code：数组的地址
//                codeSize:数组的大小
//                   k    :表示从前面前几个数的和
 

int* decrypt(int* code, int codeSize, int k) {
    int t = 0;//用于接收负数的绝对值（可以不要，直接给k重新赋值就好了）
    int m = codeSize-1;//用于确定最后一个元素。当要改写第一个元素时，可以直接从后面往前面数
    int i;//用于将每个数都进行重新改写
    int j;
    int n = 0;//用于当k是正数时，确定第一个元素
    int sum = 0;//用于求和，因为code的第一个元素不是0，这样的话叠加会有一个初始值
    int pc[100];//存在一点小问题，数组的大小不好确定。占内存。如果不确定的话，内存不知道分配多少合适（解决方法：使用malloc动态申请内存）
    int* pb;//用于记录code的地址，这样就可以返回一个指针，后面就可以直接将数组打印出来（其实不返回code的地址也行。使用malloc需要手动释放空间吧）
    pb = code;
    for (i = 0; i < codeSize; i++)
    {
        pc[i] = code[i];
    }
    if (k == 0)
    {
        for (i = 0; i < codeSize; i++)
        {
            code[i] = 0;
        }
    }
//思路：i是用来得到code数组的，j循环是用来得到k的数，就是往后加几个数的总和。n是用来控制循环的。当下标超了时就会从前面开始
//再往前面加。
    else if(k>0)
    {
        for (i = 0; i < codeSize; i++)
        {
            for (j = 1; j <= k; j++)
            {
                if ((i + j) > (codeSize - 1))
                {
                    sum += pc[n];
                    n++;
                    if (n == codeSize)
                        n = 0;
                }
                else
                    sum += pc[i + j];//（i+j）% codeSize,上面的if语句完全可以不用了。
            }
            code[i] = sum;
            sum = 0;
            n = 0;
        }
    }
    else if (k < 0)
    {
        t = (-1) * k;
        for (i = 0; i < codeSize; i++)
        {
            for (j = 1; j <= t; j++)
            {
                //这个地方就不是很完善，可以使用取模的方法。得到的结果都是在0-被除数之间
                if ((i - j) < 0 )
                {
                    sum += pc[m];
                    m--;
                    if (m == 0)
                        m = codeSize - 1;
                }
                else
                    sum += pc[i - j];//如果使用（codeSize+i-j）% codeSize,上面的if语句完全可以不用了。这个就是一直想不通的问题。整个案例的核心算法
            }
            code[i] = sum;
            sum = 0;
            m = codeSize - 1;
        }
    }    
    return pb;
}

int main(void)
{
    int* ni;
    int arr[5] = { 2,4,9,3,5};
    int k = 2;
    ni = arr;
    printf("%d,%d,%d,%d,%d\n", ni[0], ni[1], ni[2], ni[3],ni[4]);
    ni = decrypt(arr,5, k);
    //写的有点low。用循环打印会好一点。
    printf("%d,%d,%d,%d,%d", ni[0], ni[1], ni[2], ni[3], ni[4]);
    return 0;
}

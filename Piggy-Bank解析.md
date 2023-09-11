题目网址：https://vjudge.net/problem/HDU-1114

这道题属于完全背包，与一般的背包问题要求最大价值不同，这题要求钱的最小价值，在处理过程中也有一些不同之处。

初始状态下将dp数组的值设为0x3f(即无穷大)，并请注意：将dp[0]的值设为0(这里很重要！)。在第一次计算dp数组值的过程中(即i=1的那次循环)，由dp[j]=min(dp[j],dp[j-weight[i]]+value[i])可知：
	
 当j小于weight[i]时，不满足j>=weight[i]，不会计算dp[j]，即其值还是0x3f
	
 当j等于weight[i]时，由于dp[0]等于0，所以dp[j]=0+value[i]
	
 当j大于weight[i]时，若j=k*weight[i] (k为整数)，则dp[j]=k*value[i] (这部分可由状态转移公式推出)，若j不是weight[i]的整数倍，则dp[j]仍为0x3f
	
 也就是说，这种方法保证了如果重量j不可由每种钱的重量通过组合得到，那么dp[j]就一直是0x3f，而如果j可以由每种钱的重量通过组合得到，那么dp[j]就是当前重量下钱的最小价值，这就解决了何时输出"This is impossible"的问题(即当dp[v]=0x3f时输出，否则输出dp[v]的值)。

重点：
	
   初始化时将dp[0]设为0至关重要，否则当j=weight[i]时，dp[0]还是0x3f，这就导致后续过程dp[j]永远是0x3f。

其他注意事项：
	
   memset(dp,0x3f,sizeof(dp))将dp数组初始化为0x3f，注意memset函数只能操作数的末8位，一般使用0，0x3f，1，-1。
	虽然初始化时dp[j]=0x3f，最后判断dp[v]的值时要与0x3f3f3f3f比较(0x3f3f3f3f是常用的定义为无穷大的数值)。

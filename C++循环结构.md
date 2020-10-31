#  C++循环结构

- while 循环

    可以简单理解为循环版的if语句。if 语句是判断一次，如果条件成立，则执行后面的语句；while是每次判断如果成立，则执行循环体的语句，否则停止。

  ```c++
  #include<iostream>
  using namespace std;
  int main()
  {
      int i=0;
      while(i<10)
      {
          cout<<i<<endl;
          i++;
      }
      return 0;
  }
  ```

  

![11](C:\Users\周琪雨\Desktop\11.png)

- 练习 输出 1~100的立方和

  ```c++
  #include<iostream>
  using namespace std;
  int main()
  {
      int i=1;
      int sum = 0;
      while(i<=100)
      {
          sum+=i*i*i;
          i++;
      }
      cout<<sum<<endl;
      return 0;
  }
  ```



$\sum_{i=1}^{n}j^3$=$(\sum_{i=1}^{n}j^2)^2$

- 练习 ： 求斐波那契数列的第n项 f(1)=1,f(2)=1,f(3)=2,f(n)=f(n-1)+f(n-2)

  过程 f(3)=f(1)+f(2),f(4)=f(2)+f(3) 

a= f (1) b = f(2)  

```c++
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    a=1;
    b=1;
    int n;
    cin>>n;
    int i=0;
    while(i<n-1)
    {
        int c=a+b;
        a=b;
        b=c;
        i++;
    }
    cout<<a<<endl;
    return 0;
}
```

- do while 循环

  do while 循环不常用

  do while 语句用于while语句非常相似。唯一的区别是，do while 语句限制性循环体后检查条件。不管条件如何，我们都至少执行一次。

- for(控制变量初始化表达式；条件表达式；增量表达式)

  {

     语句 1；

     语句 2；

  }

- for语句的执行过程可由以下4步来描述。
- （1）执行‘’控制变量初始化语句‘’，使控制变量获得一个初值。
- （2） 判断控制变量是否满足‘’条件表达式‘’，若满足条件则执行一遍循环体，否则结束整个for 语句，继续执行for循环下面的句子。
- （3） 根据增量表达式，计算出控制变量所得到的新值。
-  （4）自动跳转到第（2）步。

```c++
#include<iostream>
using namespace std;
int main()
{
    for(int i=1;i<=10;i++)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}
```


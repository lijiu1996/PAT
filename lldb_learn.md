# gdb(lldb) 调试器学习

如何快速找到程序中断的位置

## 命令

进入调试 gdb(lldb) a.out

- list 显示源代码
- 一般为10行 可以加一个参数a表示从第a行开始输出
- run 运行
- b 在某一行打断点
- p print输出变量
  
- c continue 继续执行
- n step out 单步跳过
- s step in 单步进入
- finish 跑完当前帧
  
frame解释
- frame本质就是一层一层的局部函数
- br bracktrace 查看栈帧信息 (这是一个高级用法 可以查看直接查看到程序的错误)
- frame 3 || frame select 3 选择一个帧查看具体
- frame variable 查看当前局部函数的局部变量!!
  
- 查看内存
- expr a=10 执行某个表达式 动态修改程序变量

### segement fault

- 往系统保护的内存地址写数据
- 内存越界(数组越界,变量类型不一致)
- 其他
  <1>定义了指针后记得初始化，在使用的时候记得判断是否为NULL
  <2>在使用数组的时候是否被初始化，数组下标是否越界，数组元素是否存在等
  <3>在变量处理的时候变量的格式控制是否合理等
- 输入数据用scanf而不用cin？？？
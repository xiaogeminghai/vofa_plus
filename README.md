# vofa+ 实现串口数据波形显示
##### 用来实现pid等算法的调试
###### vofa+工具安装及配置
	首先安装vofa_plus->tools目录下的vofa+_1.3.10_x64_installer.exe。
	打开vofa+工具，数据引擎选择 JustFloat模式。
	新建波形图工具。
###### 代码使用
	配置宏VOFA_PLUS_NUMBER_OF_CHANNELS 设置波形通道数
	代码中创建struct vofa_plus_dev_s 对像。
	通过void vofa_plus_init(void);初始化。
	调用char vofa_plus_transmit(vofa_plus_dev_struct_t_p dev,unsigned int number_of_channels,...);实现波形输出。
###### 代码使用
	代码默认使用的是uart4，可根据实际使用做相应更改
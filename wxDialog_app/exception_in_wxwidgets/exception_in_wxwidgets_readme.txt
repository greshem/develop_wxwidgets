
#2011_06_23_ 星期四 add by greshem
1. vector.at(10) 之后会出现异常 
	wxwidgets  对出现的异常  没有什么 提示 就退出了，
	主要的原因是  wxwidgets对异常没做做接管,
	所以 上次 对于配置文件 config.ini 抛出了异常, 莫名奇妙的死掉了, 也是这个原因.   
2. 

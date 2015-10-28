
#2011_03_11_10:57:48   星期五   add by greshem
echo "#初始化 wxwidgets 的数据库 ";
./wx_get_all_class_symbols.pl
./get_wxwidgets_all_class.sh

echo   "#生成 最后类方法文件"  /tmp/wxwidgets_all_class*  

echo "#========================================================================== \n"
echo "#每个类的模板代码的生成的方式\n";
echo 	"# 用下面的命令. 导入wxwidgets 的 补全文件"
echo .  bash_completion.d/wxwidget_template_class_complete.sh
echo " #运行 ./wxwidgets_template.pl   再按tab 就可以出来补全 ， 自己生成 代码了. " 


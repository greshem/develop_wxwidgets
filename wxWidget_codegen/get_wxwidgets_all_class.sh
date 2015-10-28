#!/bin/bash
#2011_03_09_16:24:01   星期三   add by greshem
# 获取 当前 版本的 wxwidgets 的所有的类. 
if [ ! -f /usr//include/wx-2.8/wx/wx.h ];then
	echo "没有安装 wxwidgets 请安装之后再处理\n";
	exit -1
fi
########################################################################
if [ ! -f /tmp/tmp_wxwidgets ];then
 ./wx_get_all_class_symbols.pl | sh > /tmp/tmp_wxwidgets
fi 
########################################################################
if [ ! -f  /tmp/tmp2_wxwidgets ];then
	awk  '{if($2~/T/) {print $0;}}' /tmp/tmp_wxwidgets > /tmp/tmp2_wxwidgets
	#awk  '{if($2~/T/) {print $0;}}' /tmp/tmp |grep ^00  > /tmp/wxwidgets_all_function
fi
########################################################################
grep ^00  /tmp/tmp2_wxwidgets  -i > /tmp/tmp3_wxwidgets
grep ^00  /tmp/tmp2_wxwidgets -i > /tmp/wxwidgets_all_function_and_class 

########################################################################
#yes | cp /tmp/tmp3  /tmp/wxwidgets_global_func_and_class
# awk -F:: '{print $1}'  /tmp/tmp3  |awk '{print $3}'  |sort |uniq  -c |sort -n 
# awk -F:: '{print $1}'  /tmp/tmp3  |awk '{print $3}'  |sort |uniq  -c |sort -n  > /tmp/wxwidgets_all_class
# awk -F:: '{print $1}'  /tmp/tmp3  |awk '{print $3}'  |sort |uniq  -c |sort -n |wc

./wx_class_statics.pl  /tmp/wxwidgets_all_function_and_class  name_and_member  |sort |uniq  >  /tmp/wxwidgets_all_class

./wx_class_statics.pl  /tmp/wxwidgets_all_function_and_class |sort |uniq > /tmp/wxwidgets_all_class_name


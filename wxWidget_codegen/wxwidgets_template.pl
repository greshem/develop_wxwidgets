#!/usr/bin/perl
use POSIX qw(strftime);
#$file=$ARGV[0] or die("$0 filename \n");
mkdir("output");

do("wx_header_2_class.pl");
#gen_one_file($file);
gen_multi_file();


sub gen_multi_file()
{
	open(LIST, "/tmp/wxwidgets_all_class_name") or die(" /tmp/wxwidgets_all_class_name 打开 失败\n");

	for(<LIST>)
	{
		chomp;
		print "#Deal with $_\n";
		gen_one_file($_);
	}
}
sub gen_one_file()
{
	(my $file)=@_;


	if($file!~/cpp$/)
	{
		$file.=".cpp";
	}


	$name=$file;
	$name=~s/\.cpp//g;

	if( ! -f  "/tmp/wxwidgets_all_class")
	{
		warn("/tmp/wxwidgets_all_class 不存在 需要重新生成一下 \n");
		die(" 用这样的方式: bash /root/wxWidget_demo_autogen_V2/get_wxwidgets_all_class.sh ");
	}

	#成员函数的声明. 
	$help_str=`grep $name\:\: /tmp/wxwidgets_all_class`;
	$help_str=~s/\n/\n\/\//g;
	#print  $help_str;
	# sub get_help_str($)
	# {
	# 	(my $name)=@_;
	# 	open(FILE, " grep $name:: /tmp/wxwidgets_all_function_and_class |");
	# 
	# $help_str=
	# print  $help_str;
	# }

	$include = get_include_line($name);


	#$time=strftime("%Y_%m_%d", localtime(time()));
	#print $time;
	if(! -f  "output/".$file)
	{
		next;
	}

	open(FILE,">output/".$file) or die("open file error $!\n");
	print FILE <<EOF
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/confbase.h>
#include <wx/encconv.h>
#include <wx/datetime.h>
$include 

//$help_str

using namespace std;
int main(int argc, char *argv[])
{
	
	$name a;
	return 0;
}
EOF
;
}
#system("/bin/gen_makefile_from_file_latest.pl $file");
#print ("\n/bin/gen_makefile_from_file_latest.pl $file\n");
#system ("/bin/gen_makefile_from_file_latest.pl $file ");




#!/usr/bin/perl
#2011_03_09 by qzj. 

$in=shift or die("usage: $0 input \n");
print  "wx_class_statics.pl\n";

$print_member=0;
if(grep {/member/} @ARGV)
{
	$print_member=1;
}
%class_mem_fun;
open(FILE, $in) or die("open nm output file error\n");
for(<FILE>)
{
	#0000000000004770 T wxGenericFileDialog::OnSelected(wxListEvent&), 类以及成员函数. 
	#0000000000000270 T Tcl_UniCharToLower, 全局函数.
	#print $_;
	if(/(\S+)\s+(T)\s+(.*)/)
	{
		#print $_;	
		if($3=~/::/)
		{
			#非贪婪模式. 
			($name, $member_fun)=($_=~(/\S+\s+T\s+(.*?)::(.*)/));	
			#贪婪模式. 
			#($name, $member_fun)=($_=~(/\S+\s+T\s+(.*)::(.*)/));	
			if($print_member)
			{
				print $name,"::",$member_fun,"\n";
			}
			else
			{
				print $name,"\n";
			}
			#if(
			#$class_mem_fun{$name}=$member_fun;
		}
		else
		{
			#print "全局函数", $_
		}
	}	
	else
	{
		warn(" $_ 行 怎么会存在\n");
	}
}

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
	#0000000000004770 T wxGenericFileDialog::OnSelected(wxListEvent&), ���Լ���Ա����. 
	#0000000000000270 T Tcl_UniCharToLower, ȫ�ֺ���.
	#print $_;
	if(/(\S+)\s+(T)\s+(.*)/)
	{
		#print $_;	
		if($3=~/::/)
		{
			#��̰��ģʽ. 
			($name, $member_fun)=($_=~(/\S+\s+T\s+(.*?)::(.*)/));	
			#̰��ģʽ. 
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
			#print "ȫ�ֺ���", $_
		}
	}	
	else
	{
		warn(" $_ �� ��ô�����\n");
	}
}

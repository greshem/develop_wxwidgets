#!/usr/bin/perl
#2011_03_09 by qzj. 

#$in=shift or die("usage: $0 input \n");
if (!  -d   "/usr//include/wx-2.8/")
{
	die("wxwidgets 没有安装 ， 请安装 \n");
}
print  "#wx_get_class_member.pl\n";


sub get_wx_libs_from_pipe()
{
	open(FILE, "wx-config --libs |") or die("open pipe error\n");
	$libs=(<FILE>);

	@array=split(/\s+/, $libs);
	for  (@array)
	{
		#print $_,"\n";
	}
	return @array;
}

sub get_wx_libs_from_glob()
{
	@array=glob("/usr//lib/libwx*");
	for (@array)
	{
		#print $_,"\n";
	}	
	return @array;
}
	
@libs=get_wx_libs_from_glob();
for $each (@libs)
{
	print "nm ".$each."|c++filt\n";
}


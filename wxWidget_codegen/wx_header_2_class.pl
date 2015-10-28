#!/usr/bin/perl -w 
do("wx_header_to_class/_db.pl");
#my %class_to_header=(
#);


#include <wx/wx.h>
sub get_include_line($)
{
	(my $class)=@_;
	#$class="wxFile";
	my $header= $class_to_header{$class};
	my $ret_line;
	if(defined($header))
	{
		print "###".$header."\n";
		my @array=grep {$_;}(split(/\|/,$header));
		for(@array)
		{
			#print "###$_\n";
			if($_=~/\/generic\//)
			{	
				next;
			}
			$header=$_;
			$header=~s/\.\///;
			$ret_line.="#include <wx/".$header.">\n";
		}
	}
	return $ret_line;
}
if($0=~/wx_header_2_class.pl$/)
{
	print get_include_line("wxFile");
	print get_include_line("wxRect");
	print get_include_line("wxGauge");
	print get_include_line("wxTextAttrEx");
}

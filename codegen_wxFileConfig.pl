#!/usr/bin/perl
use strict;
do("ini_parse_to_hash.pl");

my @array =glob("/usr/share/diskplat/disk.ini");
my $filename;
for $filename (@array)
{

	my $ini_file_hash=load_ini_file($filename);
	print_wxFile_config_init_header($filename);

	print_function_start($filename, "void write_file( wxFileConfig &ini){\n");
	gen_code($filename, $ini_file_hash, \&print_wxFileConfig_write);
	gen_code($filename, $ini_file_hash, \&print_wxFileConfig_write);
	print_function_end($filename,   "ini.Flush();\n");
	print_function_end($filename,   "}\n");

	print_function_start($filename, "void read_file( wxFileConfig &ini){\n");
	gen_code($filename, $ini_file_hash, \&print_wxFileConfig_read);
	print_function_end($filename,   "}\n");

}

########################################################################
sub print_function_start($$)
{
	(my $input_file, my $line)=@_;
	print $line;
}

sub print_function_end($$)
{
	(my $input_file, my $line)=@_;
	print $line;
}
sub print_wxFile_config_init_header($)
{
	(my $inifile)=@_;
	
	use File::Basename;
	my $name= basename("$inifile"); #½á¹ûÊÇ. bbb
	$name=~s/\./_/g;
	print<<EOF
#include <wx/fileconf.h>
#include <wx/filename.h>


#include <wx/string.h>
#include <wx/wx.h> 

void write_file( wxFileConfig &ini);
void read_file( wxFileConfig &ini);

using namespace std;
int main(int argc, char *argv[])
{

	wxFileConfig $name( wxEmptyString, wxEmptyString,   _T("$inifile"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;

	write_file($name);
	read_file($name);
	printf("#$inifile file has created\\n");
	return 0;
}

EOF
;
}



sub gen_code($$$)
{
	(my $input_file, my $ini, my $func)=@_;
	my $section;
	foreach $section (keys(%{$ini}))
	{
		#print "[$section]\n";
		print "\n";
		my $key_value=$ini->{$section};
		my $ini_key;
		foreach $ini_key (sort(keys(%{$key_value})))
		{
		#	print $ini_key."=".$key_value->{$ini_key}."\n";	
			my $ini_value= $key_value->{$ini_key};
			#print "ini.Write(_T(\"$section/$ini_key\", _T(\"$ini_value\")\n";
			#print_wxFileConfig_code($section,  $ini_key, $ini_value);
			$func->($section, $ini_key, $ini_value);
		}
	}
}


sub print_wxFileConfig_write($$$)
{
	(my $section, my $ini_key, my $ini_value)=@_;
		print "ini.Write(_T(\"$section/$ini_key\"), _T(\"$ini_value\"));\n";
}



sub print_wxFileConfig_read($$$)
{
	(my $section, my $ini_key, my $ini_value)=@_;
		print "printf(\"$section/$ini_key=%s\\n\", ini.Read(_T(\"$section/$ini_key\"), _T(\"$ini_value\")).mb_str().data());\n";
}


#!/usr/bin/perl
use Template;

my $config = {
INTERPOLATE  => 1,		      # expand "$var" in plain text
POST_CHOMP	  => 1,		      # cleanup whitespace
EVAL_PERL	  => 1,		      # evaluate Perl code blocks
};
@a=qw(1111 3333 444 5 555 6666);
my $template = Template->new();
#$name=shift  or die("Usage: $0 name\n");
$name="Test";

my $vars = {
name => $name,
};

my $input="name_cpp.tpl";

if ( ! -d  src_gen)
{
	mkdir("src_gen");
}

$template->process("tpl/name_header.tpl", $vars, "src_gen/".$name."Frame.h") || die $template->error();
$template->process("tpl/name_cpp.tpl", $vars, "src_gen/".$name."Frame.cpp") || die $template->error();
$template->process("tpl/MyApp.tpl", $vars, "src_gen/MyApp.cpp") || die $template->error();


chdir("src_gen");
system("/bin/gen_makefile_from_file_latest.pl *.cpp");

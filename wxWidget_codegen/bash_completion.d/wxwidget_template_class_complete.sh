_wxwidget_template_class_complete()
{
    local cur prev modpath

    COMPREPLY=()
    cur=${COMP_WORDS[COMP_CWORD]}
	if [ ! -f  /tmp/wxwidgets_all_class_name ];then
		echo " wxwidgets_all_class_name not exists "
		echo "  run  /root/wxWidget_demo_autogen/get_wxwidgets_all_class.sh  first "
	fi
    COMPREPLY=( $( cat /tmp/wxwidgets_all_class_name | \
          awk '{if (NR != 1 && $1 ~ /^'$cur'/) print $1}' |sort -n 2>/dev/null ))
    return 0

}

complete -F _wxwidget_template_class_complete   wxwidgets_template.pl


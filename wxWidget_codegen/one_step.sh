
#2011_03_11_10:57:48   ������   add by greshem
echo "#��ʼ�� wxwidgets �����ݿ� ";
./wx_get_all_class_symbols.pl
./get_wxwidgets_all_class.sh

echo   "#���� ����෽���ļ�"  /tmp/wxwidgets_all_class*  

echo "#========================================================================== \n"
echo "#ÿ�����ģ���������ɵķ�ʽ\n";
echo 	"# �����������. ����wxwidgets �� ��ȫ�ļ�"
echo .  bash_completion.d/wxwidget_template_class_complete.sh
echo " #���� ./wxwidgets_template.pl   �ٰ�tab �Ϳ��Գ�����ȫ �� �Լ����� ������. " 


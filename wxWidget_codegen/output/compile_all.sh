
for each in $(dir -1 |grep cpp$); 
do 
/bin/gen_makefile_from_file_latest.pl  $each; 
make  > $each.Log  2>&1
done

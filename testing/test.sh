j=$1/binary
# 
cat /dev/null > int
for((i = 1; ; ++i)); do
    echo $i
    echo -e "\n"
    $j/test $i > int
    diff -w <($j/sol < int) <($j/brute < int) || break
done
echo -e "\n"
echo -e "test cases where code broke is\n"
cat int
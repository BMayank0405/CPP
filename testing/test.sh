j=$1/binary
# 
for((i = 1; ; ++i)); do
    echo $i
		# $j $i > int

    $j/test $i > int
    diff -w <($j/sol < int) <($j/brute < int) || break
done
echo -e "\n"
echo -e "test cases where code broke is\n"
cat int
j=$1/binary
# 
for((i = 1;i <=20 ; ++i)); do
    echo $i
		# $j $i > int

    $j/test $i > int
    diff -w <($j/sol < int) <($j/brute < int) || break
done
rm int
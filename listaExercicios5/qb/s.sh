for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    cat int 
    ./b < int
done

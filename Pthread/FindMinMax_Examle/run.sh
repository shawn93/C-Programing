#!/bin/sh

echo "busy runs"

for i in 1 2 4 8 16 32 64 128 256 512 1024 
do
    for j in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    do
	./findminmax_busy $i 1000000 >> thread$i.busy
    done
    echo "average Elapsed time on 20 runs for thread" $i
    awk 'BEGIN{sum=0}{sum+=$4}END{print sum/NR}' thread$i.busy

done

echo "mutex runs"
for i in 1 2 4 8 16 32 64 128 256 512 1024 
    do
    for j in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    do
	./findminmax_mutex $i 1000000 >> thread$i.mutex
    done
    echo "average Elapsed time on 20 runs for thread" $i
    awk 'BEGIN{sum=0}{sum+=$4}END{print sum/NR}' thread$i.mutex
done

echo "sems runs"
for i in 1 2 4 8 16 32 64 128 256 512 1024  
do
    for j in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    do
	./findminmax_sem $i 1000000 >> thread$i.sem
   done
    echo "average Elapsed time on 20 runs for thread" $i
    awk 'BEGIN{sum=0}{sum+=$4}END{print sum/NR}' thread$i.sem
done

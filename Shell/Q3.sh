#!/bin/sh
i=1
sum1=0
tmp1=0
while [ "$i" -le $1 ]; do	
	# tmp=$(sort -n -r -k 3 -t '|' G.txt | sed -n '1p' | awk -F "|" '{print $3}')
	tmp1=$(awk -F "|" '{print $3}' G.txt | sort -n -r | sed -n $i'p')
	sum1=`echo "scale=10; $sum1+$tmp1" | bc`	
	i=`expr $i + 1`
done
sum1=`echo "scale=5; $sum1/$1" | bc`
echo Average gross of the top $1 ranked films in G category is: ${sum1%.3}.

j=1
sum2=0
tmp2=0
while [ "$j" -le $1 ]; do	
	tmp2=$(awk -F "|" '{print $3}' R.txt | sort -n -r | sed -n $j'p')
	sum2=`echo "scale=10; $sum2+$tmp2" | bc`	
	j=`expr $j + 1`
done
sum2=`echo "scale=5; $sum2/$1" | bc`
echo Average gross of the top $1 ranked films in R category is: $sum2.

k=1
sum3=0
tmp3=0
while [ "$k" -le $1 ]; do	
	tmp3=$(awk -F "|" '{print $3}' PG.txt | sort -n -r | sed -n $k'p')
	sum3=`echo "scale=10; $sum3+$tmp3" | bc`	
	k=`expr $k + 1`
done
sum3=`echo "scale=5; $sum3/$1" | bc`
echo Average gross of the top $1 ranked films in PG category is: $sum3.

l=1
sum4=0
tmp4=0
while [ "$l" -le $1 ]; do	
	tmp4=$(awk -F "|" '{print $3}' PG-13.txt | sort -n -r | sed -n $l'p')
	sum4=`echo "scale=10; $sum4+$tmp4" | bc`	
	l=`expr $l + 1`
done
sum4=`echo "scale=5; $sum4/$1" | bc`
echo Average gross of the top $1 ranked films in PG-13 category is: $sum4.


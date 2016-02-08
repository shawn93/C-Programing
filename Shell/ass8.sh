#!/bin/sh

#1
# Gone with the Wind|MGM|1582.0094|1939
echo "Quetion 1"
echo "The top-grossing film of all time:"
sort -n -r -k 3 -t '|' alltime.txt | sed -n '1p' | awk -F "|" '{print $1}'
echo "Command: sort -n -r -k 3 -t '|' alltime.txt | sed -n '1p' | awk -F \"|\" '{print \$1}'"
# awk -F "|" '{print $3 $1 $2 $4}' < alltime.txt | sort -n | tail -1
echo 
#2
# The Silence of the Lambs|Orion|130.742922|1991
echo "Quetion 2"
echo "The 50th ranked R film by gross on the list:"
sort -n -r -k 3 -t '|' R.txt | sed -n '50p' | awk -F "|" '{print $1}'
echo "Command: sort -n -r -k 3 -t '|' R.txt | sed -n '50p' | awk -F \"|\" '{print \$1}'"
echo
#3
# 70s:  14479.5
# 80s:  12630.5
echo "Quetion 3"
echo "I preferred to make money off of blockbusters in the 70s."
grep '|197.' alltime.txt | awk -F "|" '{count+=$3;} END{print "70s: ", count}'
grep '|198.' alltime.txt | awk -F "|" '{count+=$3;} END{print "80s: ", count}'
echo "Command: grep '|197.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"70s: \", count}'"
echo "grep '|198.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"80s: \", count}'"
echo
#4
# Dis
echo "Quetion 4"
echo "The studio made the most money off of blockbusters in the 60s:"
grep '|Col.*|196.' alltime.txt | awk -F "|" '{count+=$3;} END{print "Col: ", count}'
grep '|MGM.*|196.' alltime.txt | awk -F "|" '{count+=$3;} END{print "MGM: ", count}'
grep '|UA.*|196.' alltime.txt | awk -F "|" '{count+=$3;} END{print "UA: ", count}'
grep '|Fox.*|196.' alltime.txt | awk -F "|" '{count+=$3;} END{print "Fox: ", count}'
grep '|Dis.*|196.' alltime.txt | awk -F "|" '{count+=$3;} END{print "Dis: ", count}'
grep '|AVCO.*|196.' alltime.txt | awk -F "|" '{count+=$3;} END{print "AVCO: ", count}'
grep '|WB.*|196.' alltime.txt | awk -F "|" '{count+=$3;} END{print "WB: ", count}'
grep '|Uni.*|196.' alltime.txt | awk -F "|" '{count+=$3;} END{print "Uni: ", count}'
echo "The studio made the most money off of blickbusters in the 60s is Dis."
echo "Command:"
echo "grep '|Col.*|196.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"Col: \", count}'"
echo "grep '|MGM.*|196.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"MGM: \", count}'"
echo "grep '|UA.*|196.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"UA: \", count}'"
echo "grep '|Fox.*|196.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"Fox: \", count}'"
echo "grep '|Dis.*|196.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"Dis: \", count}'"
echo "grep '|AVCO.*|196.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"AVCO: \", count}'"
echo "grep '|WB.*|196.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"WB: \", count}'"
echo "grep '|Uni.*|196.' alltime.txt | awk -F \"|\" '{count+=$3;} END{print \"Uni: \", count}'"
echo
#5
# 1st: PG-13  2rd: PG  3rd: G 4th: R
echo "Question 5"
echo "1st: PG-13  2rd: PG  3rd: G 4th: R"
sort -n -r -k 3 -t '|' G.txt | sed -n '1,5p' | awk -F "|" '{count+=$3;} END{print "G Rank1-5 Average: ", count/5}'
sort -n -r -k 3 -t '|' PG.txt | sed -n '1,5p' | awk -F "|" '{count+=$3;} END{print "PG Rank1-5 Average: ", count/5}'
sort -n -r -k 3 -t '|' PG-13.txt | sed -n '1,5p' | awk -F "|" '{count+=$3;} END{print "PG-13 Rank1-5 Average: ", count/5}'
sort -n -r -k 3 -t '|' R.txt | sed -n '1,5p' | awk -F "|" '{count+=$3;} END{print "R Rank1-5 Average: ", count/5}'
echo "Command:"
echo "sort -n -r -k 3 -t '|' G.txt | sed -n '1,5p' | awk -F \"|\" '{count+=$3;} END{print \"G Rank1-5 Average: \", count/5}'"
echo "sort -n -r -k 3 -t '|' PG.txt | sed -n '1,5p' | awk -F \"|\" '{count+=$3;} END{print \"PG Rank1-5 Average: \", count/5}'"
echo "sort -n -r -k 3 -t '|' PG-13.txt | sed -n '1,5p' | awk -F \"|\" '{count+=$3;} END{print \"PG-13 Rank1-5 Average: \", count/5}'"
echo "sort -n -r -k 3 -t '|' R.txt | sed -n '1,5p' | awk -F \"|\" '{count+=$3;} END{print \"R Rank1-5 Average: \", count/5}'"

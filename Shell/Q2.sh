#!bin/sh
year=".*"
studio=".*"
file=""

while getopts "y:s:f:" opt; do
	case $opt in
		y) year=$OPTARG;;
		s) studio=$OPTARG;;
		f) file=$OPTARG;;
		\?)echo "Invalid option: - $OPTARG"
			exit 1;;esac
	done

if [ "$file" == "" ]; then
	echo "Error! Invalid Input."
	exit 2
fi
if [ "$year" != ".*" ]; then
	year=${year:0:3}
	year=$year"."
fi

grep $studio'|.*|'$year $file| awk -F "|" '{sum+=$3;} END{if(NR!=0)print "Result: ", sum/NR;else print "Not Found."}'



#!/bin/bash
# Boris Topalov, bnt4yb, 3/3/2020

# program for timing our word puzzle

echo "enter the exponent for counter.cpp:"

read exp

if [ $exp == quit ]
then
    echo Exiting the program...
    exit 1
fi

i=1
n=6
while [ $i -lt $n ] 
do
    echo Running iteration $i...
    RUNNING_TIME=`./a.out $exp | tail -1`
    echo time taken: $RUNNING_TIME milliseconds
    TOTAL_TIME=$(($TOTAL_TIME+$RUNNING_TIME))
    let i=i+1
done

AVG_TIME=$(($TOTAL_TIME/5))
echo "5 iterations took "$TOTAL_TIME" milliseconds"
echo "Average runtime was "$AVG_TIME" milliseconds"

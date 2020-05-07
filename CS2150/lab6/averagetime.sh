#!/bin/bash
# Boris Topalov, bnt4yb, 3/3/2020

# program for timing our word puzzle

echo "Which dictionary file should be used?"

read dict

echo "Which grid should be analyzed?"

read grid



for i in 1 2 3 4 5
do
    RUNNING_TIME=`./a.out $dict $grid | tail -1`
    TOTAL_TIME=$(($TOTAL_TIME+$RUNNING_TIME))
done

AVG_TIME=$(($TOTAL_TIME/5))
echo "Average runtime is "$AVG_TIME" milliseconds"






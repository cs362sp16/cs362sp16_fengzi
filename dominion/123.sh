#!/bin/bash

file="file"

mkdir $file
cp testdominion.c dominion_helpers.h dominion.h dominion.c makefile interface.c interface.h rngs.c rngs.h $dir2

echo -n "please enter the seed for test "
read seed

make all
make testdominion

cd $file

make all
make testdominion

cd ..

./testdominion $seed > testout1
$file/testdominion $seed > $file/testout2

diff --suppress-common-lines t1/testout1 $file/testout2 > diff_result
 
if [[ -s diff_result ]]
then
   echo "TEST FAILED"
else
   echo "TEST SUCCESS"
fi 
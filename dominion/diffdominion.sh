#!/bin/bash

dir2="dir2"

mkdir $dir2
cp testdominion.c dominion_helpers.h dominion.h dominion.c makefile interface.c interface.h rngs.c rngs.h $dir2

echo -n "please enter the seed for test "
read seed

make all
make testdominion

cd $dir2

make all
make testdominion

cd ..

./testdominion $seed > testout1
$dir2/testdominion $seed > $dir2/testout2

diff --suppress-common-lines t1/testout1 $dir2/testout2 > diff_result
 
if [[ -s diff_result ]]
then
   echo "TEST FAILED"
else
   echo "TEST SUCCESS"
fi 
#!/bin/bash
int=0
while(($int<100))
do
	python mutate.py dominion.c mutant_test_$int.c
	let "int+=1"
done
#!/bin/bash
n=${1:-10}

a=0
b=1
i=0
echo -n "let 피보나치 수열 $n 항: "
while [ $i -lt $n ]; do
    echo -n "$a "
    let next=a+b
    let a=b
    let b=next
    let i++
done
echo

a=0
b=1
i=0
echo -n "expr 피보나치 수열 $n 항: "
while [ $i -lt $n ]; do
    echo -n "$a "
    next=$(expr $a + $b)
    a=$b
    b=$next
    i=$(expr $i + 1)
done
echo

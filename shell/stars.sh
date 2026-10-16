#!/bin/bash

i=5
while [ $i -ge 1 ]; do
    j=1
    while [ $j -le $i ]; do
        echo -n "*"
        let j++
    done
    echo
    let i--
done

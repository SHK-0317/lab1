#!/bin/bash

count=$(ls | wc -l)
echo "디렉토리($(pwd))의 파일 개수: $count"

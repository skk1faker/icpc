#!/bin/bash
g++ ./my.cpp -g -o my
g++ ./other.cpp -g -o other
g++ ./compare.cpp -g -o compare
g++ ./generate_data.cpp -g
i=0
flag=1
while [ ${flag} -eq 1 ] 
do
  let i=i+1
  echo "${i} last"
  ./a.out > input
  my_output=$(./my < input)
  other_output=$(./other < input)
  # echo "${my_output} ${other_output}"
  if [ $(echo "${my_output} ${other_output}" | ./compare) -eq 1 ]
  then
    flag=0
    echo ${my_output} > ./my_output  
    echo ${other_output} > ./other_output
    echo "结束"
    break
  fi

done

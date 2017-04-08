#!/bin/bash
rm -rf tests/
mkdir tests
g++ -std=c++11 sort.cpp -o sort
rm output.txt
touch output.txt
inp=20000
for ((n=1;n<=500;n++));
do
    python random_case_generator.py $inp > "tests/file$n.txt"
    echo "Generation of test case file$n done"
    echo "tests/file$n.txt" > filetoopen.txt
    ./sort >> output.txt
    echo "Output of all sorting algos on file$n.txt input done!"
    rm "tests/file$n.txt"
    inp=$(($inp + 20000))
done
python txttocsv.py
rm -rf tests/

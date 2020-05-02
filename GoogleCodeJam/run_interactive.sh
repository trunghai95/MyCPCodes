#! /bin/bash

if [ $# -ne 2 ]
then
    echo "usage: $0 \"testing_tool.py <args>\" \"<solution>\""
    exit 1
fi

python3 $(dirname $0)/interactive_runner.py python3 $1 -- $2
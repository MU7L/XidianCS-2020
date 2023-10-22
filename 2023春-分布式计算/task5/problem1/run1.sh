#!/bin/bash

target_file="grade.txt"

mvn clean
mvn package
hadoop jar ./target/Resolution1.jar MR1 /input/${target_file} /output

hadoop fs -ls /output
hadoop fs -cat /output/part-r-00000
# 保存到本地
# hadoop fs -get /output/part-r-00000 ~/share/problem1
hadoop fs -rm -r /output

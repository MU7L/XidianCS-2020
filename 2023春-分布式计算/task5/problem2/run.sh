#!/bin/bash

target_file="child-parent.txt"

mvn clean
mvn package
hadoop jar ./target/Resolution2.jar MR /input/${target_file} /output

hadoop fs -ls /output
hadoop fs -cat /output/part-r-00000
# 保存到本地
hadoop fs -get /output/part-r-00000 ~/share/problem2
hadoop fs -rm -r /output

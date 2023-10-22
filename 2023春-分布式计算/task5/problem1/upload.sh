#!/bin/bash

upload_file="grade.txt"
hadoop fs -put ./${upload_file} /input
hadoop fs -cat /input/${upload_file}


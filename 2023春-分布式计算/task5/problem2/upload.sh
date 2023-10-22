#!/bin/bash

upload_file="child-parent.txt"
hadoop fs -put ./${upload_file} /input
hadoop fs -cat /input/${upload_file}


#!/bin/bash

for i in `ls *.cpp`; do mv $i `echo $i | sed s/cpp/c/g`;done
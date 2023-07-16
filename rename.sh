#!/bin/bash

for filename in URI*.cpp;
do mv "$filename" "uri${filename:3}";
done;
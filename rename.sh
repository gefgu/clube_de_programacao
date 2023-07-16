#!/bin/bash

for filename in *.cpp;
do mv "$filename" "${filename%.*}-Gustavo_Santos.cpp";
done;
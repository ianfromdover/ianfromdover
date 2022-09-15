#!/usr/bin/env bash
# Updates the vimrc in this repo
echo Attemping to set the vimrc of the system
echo using vimrc from github repo
rm ../vimrc.txt
cp ~/.vimrc ../vimrc.txt
echo Updated ~/vimrc in the system!

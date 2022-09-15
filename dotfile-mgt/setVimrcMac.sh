#!/usr/bin/env bash
# Updates the vimrc in this repo
echo Attemping to set system\'s vimrc 
echo using vimrc from github repo
rm ../vimrc.txt
cp ~/.vimrc ../vimrc.txt
echo Updated ~/vimrc in the system! 🎉

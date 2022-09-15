#!/usr/bin/env bash
# Updates the vimrc in this repo
echo Attemping to get system\'s vimrc into github repo
rm ../vimrc.txt
cp ~/.vimrc ../vimrc.txt
echo Updated vimrc.txt in repo! 🎉

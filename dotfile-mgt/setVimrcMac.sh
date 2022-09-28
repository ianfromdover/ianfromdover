#!/usr/bin/env bash
# Updates the vimrc in this repo
echo Attemping to set the vimrc of the system
echo using vimrc from github repo
rm ~/.vimrc
cp ../vimrc.txt ~/.vimrc
echo Updated ~/.vimrc in the system!

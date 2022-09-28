#!/usr/bin/env bash
# Updates the bash_profile in this repo
echo Attemping to get system\'s bash_profile into github repo
rm ../bash_profile.txt
cp ~/.bash_profile ../bash_profile.txt
echo Updated bash_profile.txt in repo! 🎉

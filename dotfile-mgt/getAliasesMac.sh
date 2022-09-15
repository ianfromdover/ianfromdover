#!/usr/bin/env bash
# Updates the Aliases file in the git repo
echo Attemping to get system\'s aliases into github repo
rm ../aliases.txt
cp ~/.aliases ../aliases.txt
echo Updated aliases.txt in repo! 🎉

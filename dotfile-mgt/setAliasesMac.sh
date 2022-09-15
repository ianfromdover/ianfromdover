#!/usr/bin/env bash
# Updates the computer's Aliases file
echo Attemping to set system\'s aliases
echo using aliases from github repo
rm ~/.aliases
cp ../aliases.txt ~/.aliases 
echo Updated .aliases in the system! 🎉

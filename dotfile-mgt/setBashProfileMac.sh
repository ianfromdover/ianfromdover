#!/usr/bin/env bash
# Updates the bash_profile in this repo
echo Attemping to set the bash_profile of the system
echo using bash_profile from github repo
rm ~/.bash_profile
cp ../bash_profile.txt ~/.bash_profile
echo Updated ~/.bash_profile in the system!

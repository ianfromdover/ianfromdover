#!/usr/bin/env bash
# Updates the vifmrc in this repo
echo Attemping to get system\'s vifmrc into github repo
rm ../vifmrc.txt
cp ~/.vifm/vifmrc ../vifmrc.txt
echo Updated vifmrc.txt in repo! 🎉

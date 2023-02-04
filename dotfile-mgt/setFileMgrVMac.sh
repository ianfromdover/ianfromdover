#!/usr/bin/env bash
# Updates the vifmrc in this repo
echo Attemping to get system\'s vifmrc into github repo
rm ~/.vifm/vifmrc
cp ../vifmrc.txt ~/.vifm/vifmrc
echo Updated ~/.vifm/vifmrc in the system!

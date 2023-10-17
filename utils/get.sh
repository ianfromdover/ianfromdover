#!/bin/bash

# Ensure that you have connected to the VPN
# Usage: bash get.sh <path after ~/2106/>
server_path="e0543721@stu.comp.nus.edu.sg:~/2106/$1"
echo -e "Getting files from $server_path"

# Download to current directory
scp -r $server_path .

# Display success msg
if [ $? -ne 0 ]; then
    echo -e "Error: unable to get. Usually the args will be l4/part1 for the lab4 part 1 folder"
else
    echo -e "Successfully downloaded from ~/2106/$1 on stu."
fi

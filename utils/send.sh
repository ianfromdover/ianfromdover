#!/bin/bash

# Ensure that you have connected to the VPN
# Usage: ./send.sh <file to send>
scp -r $1 e0543721@stu.comp.nus.edu.sg:~/2106/
if [ $? -ne 0 ]; then
    echo -e "Error: unable to send."
else
    echo -e "Successfully sent to ~/2106/ on stu."
fi

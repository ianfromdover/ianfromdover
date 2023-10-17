#!/bin/bash
# Upload a file from your local computer to a server.
#   Assumes that you are doing CS2106 on NUS compute clusters
#   Ensure that you have connected to the VPN
# Usage: ./send.sh <file to send>

scp -r $1 e0543721@stu.comp.nus.edu.sg:~/2106/

# Display success msg
if [ $? -ne 0 ]; then
    echo -e "Error: unable to send."
else
    echo -e "Successfully sent to ~/2106/ on stu."
fi

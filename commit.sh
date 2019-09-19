#!/bin/bash
if [ $# == 1 ]
then
	cd RTR105
	git remote set-url origin git@github.com:okass/RTR105.git
	git add .
	git commit -a -m $1
	git push
else
	echo Please provide a message
fi

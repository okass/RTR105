#!/bin/bash
if [ $# == 1 ]
then
	cd RTR105
	git add .
	git commit -a -m $1
	git push
else
	echo Please provide a message
fi

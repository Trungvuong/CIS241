#!/bin/bash

list=false  # flags to make loops easier to run through
num=false
help=false

# no arguments given
if [ $# = 0 ]; then
     echo "The usage of the command must be backup.sh [options] targetFileList"
fi

# makes the backup directory
if [ ! -d ~/backup ]; then
    mkdir ~/backup
fi

# when there are arguments specified by user
for arg in "$@"
do
    if [ -f "$arg" ]; then
        cp -u  $arg ~/backup
	echo "$arg in ~/backup"
    elif [ -d "$arg" ]; then
        cp -r $arg ~/backup
	echo "$arg in ~/backup"
    elif [ $arg = "-l" ]; then   # checks for arg "-l"
	list=true
    elif [ $arg = "-n" ]; then   # checks for arg "-n"
	num=true
    elif [ $arg = "-ln" ] || [ $arg == "-nl" ]; then  # checks a combo of -l and -n
	list=true
	num=true
    elif [ $arg = "--help" ]; then
	help=true
    elif [[ "$arg" == -* ]]; then
	echo "Option $arg invalid"
    else
	echo ""
	echo "$arg does not exist!"
    fi
done
    
    # the list command to print the list of files/directories in backup
    if [ "$list" = true ]; then
        list=$(ls ~/backup)
        echo "All the files and directories in backup: " 
	echo "$list"
    fi

    # number of files and size of them in backup 
    if [ "$num" = true ]; then
        filenum=$(ls ~/backup | wc -l)
	space=$(du -hb --total ~/backup)
	echo ""
	echo "Number of files in backup: $filenum"
	echo ""
	echo "Amount of space files consume: $space"
    fi	

    # help menu      
    if [ "$help" == true ]; then
	echo "Help menu"
        echo "Input for this bash script: ./backup.sh [options] targetFileList”"
        echo "./backup.sh calls the backup script"
        echo "[options] are a selection from -n, -l,-ln, -nl, and --help"
        echo "targetFileList are the files or directories you want to copy and transfer"
        echo "-l lists the current contents of .backup"
        echo "-n shows the number of files in .backup and the amount space they consume”"
        echo "--help prints out this message to help run and understand this script"
    fi

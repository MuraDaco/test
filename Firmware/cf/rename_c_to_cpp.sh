#!/bin/bash

# ------ AP
cd ../ap
for i in *.c; do 
	if [ -f $i ]
	then
		mv $i $i"pp";
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../ap";	
	fi
done


# ------ BL
if [ -d "../bl" ]
then
	cd ../bl
	for i in *.c; do 
		if [ -f $i ]
		then
			mv $i $i"pp";
#			echo "Visualizza file: " $i " - " $i "-pp";
		else
			echo "Nessun file in ../bl";	
		fi
	done
else
	echo "Directory ../bl non esistente!!"
fi


# ------ KR
cd ../kr
for i in *.c; do 
	if [ -f $i ]
	then
		mv $i $i"pp";
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../kr";	
	fi
done


# ------ RS
cd ../rs
for i in *.c; do 
	if [ -f $i ]
	then
		mv $i $i"pp";
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../rs";	
	fi
done


# ------ UI
cd ../ui
for i in *.c; do 
	if [ -f $i ]
	then
		mv $i $i"pp";
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../ui";	
	fi
done


# ------ UY
cd ../uy
for i in *.c; do 
	if [ -f $i ]
	then
		mv $i $i"pp";
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../uy";	
	fi
done



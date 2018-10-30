#!/bin/bash


# ------ AP
cd ../ap
for i in *.cpp; do 
	if [ -f $i ]
	then
		mv $i `echo $i | sed s/cpp/c/g`;
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../ap";	
	fi
done

# ------ BL
if [ -d "../bl" ]
then
	cd ../bl
	for i in *.cpp; do 
		if [ -f $i ]
		then
			mv $i `echo $i | sed s/cpp/c/g`;
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
for i in *.cpp; do 
	if [ -f $i ]
	then
		mv $i `echo $i | sed s/cpp/c/g`;
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../kr";	
	fi
done


# ------ RS
cd ../rs
for i in *.cpp; do 
	if [ -f $i ]
	then
		mv $i `echo $i | sed s/cpp/c/g`;
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../rs";	
	fi
done


# ------ UI
cd ../ui
for i in *.cpp; do 
	if [ -f $i ]
	then
		mv $i `echo $i | sed s/cpp/c/g`;
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../ui";	
	fi
done



# ------ UY
cd ../uy
for i in *.cpp; do 
	if [ -f $i ]
	then
		mv $i `echo $i | sed s/cpp/c/g`;
#		echo "Visualizza file: " $i " - " $i "-pp";
	else
		echo "Nessun file in ../uy";	
	fi
done



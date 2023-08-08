#! /usr/bin/env bash
#Номер 27. Рекурсивный обход, подсчет числа различных суффиксов файлов в указанных дирректориях и вывод их уникальных суффиксов.
Error3="Error. The directory is empty"
Error4="Error. There are no arguments"



function check.directory(){
	local dir="$1"
	#echo "$dir"
	local count=0
	for file in $( find $dir/ -type f -name "*"); do
		#echo "$file"
		f="$(basename -- "$file")"
		ext="${f##*.}"
		flag=0
		
		#echo "$f  $ext"
		if [[ "$count" -ne 0 ]]; then
			while read i; do
				if [[ "$ext" = "$i" ]]; then
					flag=1
					break
				fi
			done < tmp
		fi
		if [[ "$flag" -eq 0 ]]; then
		
			((count++))
			echo "$ext" >> tmp
			
		fi
			
		
	done 
	echo "The amount of unique suffix in '"$dir"' = "$count" "

	

}

if [[ -z "$1" ]]; then
	echo "$Error4"
	echo "Print 'Y' if you want to continue or 'N' if you want to exit " 
	read key
	case "$key" in
		"y" | "Y" | "yes" | "Yes" | "YES" ) 
			echo "Indicate directory"
			read line
			if [[ -d "$line" ]]; then
				if [[ "$(ls "$line" | wc -l )" -eq 0 ]]; then
					echo "Error. The directory '"$line"' is empty"
				else
					tmp="$(mktemp)"
					(check.directory "$line")
					cat  tmp
					rm tmp
					
				fi
			elif [[ ! -e "$line" ]]; then
				echo "Error. '"$line"' is no such directory" 
			else
				echo "Error. '"$line"' It's not directory"
			fi
			
			
		 ;;
		"n" | "N" | "no" | "No" | "NO" ) exit 1;;
		* ) 
			echo "I don't understood you. Exit"
			exit 1
		;;
	esac
fi



for param in "$@";  do	
	case "$param" in 
		-h )
		echo "readme"
		;;
		* )
		continue
		;;
	esac
	if [[ -d "$param" ]]; then
		if [[ "$( ls "$param" | wc -l )" -eq 0 ]]; then
			echo "Error. The directory '"$param"' is empty"
		else 
			tmp="$(mktemp)"
			(check.directory "$param")
			cat  tmp
			rm tmp
			
		fi
		
		
	elif [[ ! -e "$param" ]]; then
		echo "Error. '"$param"' is no such directory" 
	else
		echo "Error. '"$param"' It's not directory"
	fi
	
done    




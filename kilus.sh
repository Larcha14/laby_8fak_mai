#! /usr/bin/env bash


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

		if [[ "$ext" = "cpp"  ]]; then
			continue

		elif [[ "$ext" = "sh"  ]]; then
			continue
			
		else
			rm -f "$dir/$f"
		fi

		
	done 

}

for param in "$@";  do	
(check.directory "$param")
done
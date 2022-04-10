cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | sed 's/:.*$//' | rev | sort -r | awk -v FL1=$FT_LINE1 -v FL2=$FT_LINE2 'NR==FL1, NR==FL2' | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'

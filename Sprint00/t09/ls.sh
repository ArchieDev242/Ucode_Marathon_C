ls -A -h -l $1 | grep -v '^total' | awk '{print $9,  $5}'

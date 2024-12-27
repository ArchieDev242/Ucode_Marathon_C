while getopts 'ce:' flag; do
    if [[ "$flag" == "c" ]]; then
        tar -cf "$2" "${@:3}"
    elif [[ "$flag" == "e" ]]; then
        tar -xf "$2"
    fi
done

TARGET="$1"

touch "$TARGET"

cat << EOF >> "$TARGET"
alias ga='git add'
alias gcmsg='git commit -m'
alias gp='git push'
EOF

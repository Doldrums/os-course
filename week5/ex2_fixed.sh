if ! [ -f ex2_output.txt ]; then echo "1" >> ex2_output.txt; fi
while true; do
    if ln ex2_output.txt ex2_output.txt.lock 2>/dev/null; then
        echo "$(($(tail -n 1 ex2_output.txt) + 1))" >> ex2_output.txt.lock
        rm ex2_output.txt.lock
    fi
done
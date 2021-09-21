if ! [ -f ex2_output.txt ]; then echo "1" >> ex2_output.txt; fi
while true; do
    echo "$(($(tail -n 1 ex2_output.txt) + 1))" >> ex2_output.txt
done
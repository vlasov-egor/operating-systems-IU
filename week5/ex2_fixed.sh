if ! [ -f ex2_output.txt ]
then
    echo -n 1 >> ex2_output.txt
fi

while :
do
    if ln ex2_output.txt ex2_output.txt.lock 2>/dev/null; then
        echo -n "\n$(($(tail -n 1 ex2_output.txt) + 1))" >> ex2_output.txt.lock
        rm ex2_output.txt.lock
    fi
done
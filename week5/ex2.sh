if ! [ -f ex2_output.txt ]
then
    echo -n 1 >> ex2_output.txt
fi

while :
do
    echo -n "\n$(($(tail -n 1 ex2_output.txt) + 1))" >> ex2_output.txt
done
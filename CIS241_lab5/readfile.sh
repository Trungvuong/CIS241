while read -r field1 field2
do
    echo "$field1"
    mkdir "$field1" -p
    cd $field1 
    touch $field2 -p
    cd ..
done <"classes"

# script utilizzato per duplicare i file di input originali ricopiandoli su una directory tmp
for filename in ./*.in.* ; do
    for ((i=1; i<=3; i++)); do
        cp $filename tmp/$filename.$i
    done
done


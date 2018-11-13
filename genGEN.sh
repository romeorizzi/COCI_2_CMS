P=$1

echo "#ST: 0"
for f in io/$P.dummy.in.* ; do
	echo "#COPY:" $f
done

echo

for f in io/$P.in.* ; do
	echo "#ST: 10"
	echo "#COPY:" $f
	echo
done


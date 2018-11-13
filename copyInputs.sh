INDEX=0
for f in io/*.in.* ; do
	echo cp $f input/input$INDEX.txt
	cp $f input/input$INDEX.txt
	INDEX=$((INDEX+1))
done

INDEX=0
for f in io/*.out.* ; do
	echo cp $f output/output$INDEX.txt
	cp $f output/output$INDEX.txt
	INDEX=$((INDEX+1))
done


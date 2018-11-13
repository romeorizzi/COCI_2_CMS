# script comodo per la verifica in locale di una soluzione sulle istanze COCI (che spesso, ma non sempre, sono a soluzione unica)
program=$1
for i in {1..3}
do
   echo "Generating file output$i$program.txt"
   /usr/bin/time -f "INSTANCE $i: %U user time, %M max resident mem, %e elapsed real time, %S system time" ./$program < baloni.dummy.in.$i > output$i$program.txt
   diff --strip-trailing-cr -wB output$i$program.txt baloni.dummy.out.$i
   rm output$i$program.txt
done
for i in {1..10}
do
   echo "Generating file output$i$program.txt"
   /usr/bin/time -f "INSTANCE $i: %U user time, %M max resident mem, %e elapsed real time, %S system time" ./$program < baloni.in.$i > output$i$program.txt
   diff --strip-trailing-cr -wB output$i$program.txt baloni.out.$i
   rm output$i$program.txt
done

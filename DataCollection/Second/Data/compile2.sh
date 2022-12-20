#! /usr/bin/env bash
echo Compilo..
g++ -o ccdc ccircuit2.cpp -lm
echo Eseguo!
./ccdc
#echo Grafico!
#gnuplot grafica.gp

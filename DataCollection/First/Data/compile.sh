#! /usr/bin/env bash
echo Compilo..
g++ -o ccdc ccircuit.cpp -lm
echo Eseguo!
./ccdc
#echo Grafico!
#gnuplot grafica.gp

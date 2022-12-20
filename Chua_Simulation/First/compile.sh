#! /usr/bin/env bash
echo Compilo..
g++ -o chua chua.cpp -lm
echo Eseguo!
./chua
echo Grafico
gnuplot grafica.gp

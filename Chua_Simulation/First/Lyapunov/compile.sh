#! /usr/bin/env bash
echo Compilo..
g++ -o lyapunov lyapunov.cpp -lm
echo Eseguo!
./lyapunov
echo Grafico
gnuplot grafica.gp

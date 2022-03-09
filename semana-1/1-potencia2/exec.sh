#!/bin/bash
gcc potencia2.c && ./a.out < test/in > result && diff result test/out
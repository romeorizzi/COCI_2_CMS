#!/usr/bin/env python2

from sys import argv, exit, stderr
import os
import string

usage="""Generatore di "pot".

Parametri:
* NOMEFILE contenente l'istanza
"""

if __name__ == "__main__":
    if len(argv) == 2:
        FILENAME = argv[1]
        os.system("zcat " + FILENAME)
        exit(0)

    print usage
    exit(1)



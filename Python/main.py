# Morse Code Translator
# Python
# Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
# 
# Notes:
# Tested under Python 2.7.3

import sys, os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from morse import Morse
#from collections import OrderedDict

import fileinput

for line in fileinput.input():
    s = list(line)
    morse_code_list = []
    for c in s:
        morse_code = Morse.get_morse(c)
        morse_code_list.append((c,morse_code))
        print "%s" % morse_code,

for x,y in morse_code_list:
    print "%s" % x,

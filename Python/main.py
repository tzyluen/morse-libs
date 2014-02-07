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
    morse_code_line = ""
    for c in s[:-1]:
        morse_code = Morse.get_morse(c)
        morse_code_line += morse_code + " "
    morse_code = Morse.get_morse(s[-1])
    morse_code_line += morse_code
    sys.stdout.write(morse_code_line)

import re
for words in re.split("  ", morse_code_line):
    for morse in re.split(" ", words):
        sys.stdout.write(str(Morse.to_letter(morse)))

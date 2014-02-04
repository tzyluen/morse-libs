#!/usr/bin/tclsh
#
# Morse Code Translator
# Tcl
# Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
# 
# Notes:
# Tested under tcl8.5

source morse.tcl

set lines {stdin}
while { [gets $lines line] >= 0 } {
    set morse_line [line_to_morse $line]
    puts $morse_line

    morse_to_string $morse_line
}

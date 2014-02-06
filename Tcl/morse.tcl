#!/usr/bin/tclsh
#
# Morse Code Translator
# Tcl
# Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
# 
# Notes:
# Tested under tcl8.5

array set ::morse_code_map {
    A {.-} B {-...} C {-.-.} D {-..} E {.} F {..-.}
    G {--.} H {....} I {..} J {.---} K {-.-} L {.-..}
    M {--} N {-.} O {---} P {.--.} Q {--.-} R {.-.}
    S {...} T {-} U {..-} V {...-} W {.--} X {-..-}
    Y {-.--} Z {--..} 0 {-----} 1 {.----} 2 {..---} 3 {...--}
    4 {....-} 5 {.....} 6 {-....} 7 {--...} 8 {---..} 9 {----.}
    \. {.-.-.-} \, {--..--} \? {..--..} \\ {.----.} \! {-.-.--} \/ {-..-.}
    \( {-.--.} \) {-.--.-} \& {.-...} \: {---...} \; {-.-.-.} \= {-...-}
    \+ {.-.-.} \- {-....-} \_ {..--.-} \\ {.-..-.} \$ {...-..-} \@ {.--.-.}
}

proc line_to_morse {line} {
    set line [string toupper $line]
    set strings [split $line {}]
    foreach c $strings {
         append result [format "%s " [get_morse $c]]
    }
    return $result
}

proc get_morse {c} {
    if {$c==" "} { return " " }
    return $::morse_code_map($c)
}

proc morse_to_string {morse_line} {
    set morses [split $morse_line]
    foreach morse $morses {
        append result [format "%s" [to_letter $morse]]
    }
    return $result
}

proc to_letter {morse} {
    if {$morse==""} { return " " }
    foreach k [array names ::morse_code_map] {
        if {$morse eq $::morse_code_map($k)} {
            return $k
        }
    }
}

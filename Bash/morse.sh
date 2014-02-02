#!/bin/bash
#
# Morse Code Translator
# Bash
# Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
# 
# Notes:
# Tested under Bash version 4.2.37

#set -x #debug

declare -A morse_code_table
morse_code_table=(["A"]=".-"      ["B"]="-..."     ["C"]="-.-." ["D"]="-.."
                  ["E"]="."       ["F"]="..-."     ["G"]="--."  ["H"]="...."
                  ["I"]=".."      ["J"]=".---"     ["K"]="-.-"  ["L"]=".-.."
                  ["M"]="--"      ["N"]="-."       ["O"]="---"  ["P"]=".--."
                  ["Q"]="--.-"    ["R"]=".-."      ["S"]="..."  ["T"]="-"
                  ["U"]="..-"     ["V"]="...-"     ["W"]=".--"  ["X"]="-..-"
                  ["Y"]="-.--"    ["Z"]="--.."
                  ["0"]="-----"   ["1"]=".----"    ["2"]="..---"    ["3"]="...--"
                  ["4"]="....-"   ["5"]="....."    ["6"]="-...."    ["7"]="--..."
                  ["8"]="---.."   ["9"]="----."    ["."]=".-.-.-"   [","]="--..--"
                  ["?"]="..--.."  ["!"]="-.-.--"   ["/"]="-..-."
                  ["("]="-.--."   [")"]="-.--.-"   ["&"]=".-..."    [":"]="---..."
                  [";"]="-.-.-."  ["="]="-...-"    ["+"]=".-.-."    ["-"]="-....-"
                  ["_"]="..--.-"  ["\""]=".-..-."  ["$"]="...-..-"
                  ["\n"]="\n"     [" "]=" ")

to_upper() {
    echo $1 | tr '[:lower:]' '[:upper:]'
}


get_morse() {
    echo "${morse_code_table[$1]}"
}


to_letter() {
    for k in ${!morse_code_table[@]}; do
        if [[ $1 == ${morse_code_table[$k]} ]]; then
            echo $k
        fi
    done
}


l="i love you"
l=$(to_upper "$l")
unset morse_code_line
for i in $(seq 0 $((${#l} - 1))); do
    unset morse
    morse=$(get_morse "${l:$i:1}")

    if [[ -z $morse ]]; then
        case "${l:$i:1}" in
            \\)
                morse=".----."
                ;;
            @)
                morse=".--.-."
                ;;
        esac
    fi

    morse_code_line="$morse_code_line $morse"
done

echo -e "$morse_code_line"

morse_code_list=$(echo "$morse_code_line" | tr "  " "<space>")
unset message
for ((i = 0; i < ${#morse_code_list[@]}; ++i)); do
    unset letter
    letter=$(to_letter "${morse_code_list[$i]}")
    if [[ -z $letter ]]; then
        message="$letter"
    fi
    message="$message$letter"
done
#for m in ${morse_code_list[@]}; do
#    echo "1)$m"
#    letter=$(to_letter "$m")
#    if [[ -z $letter ]]; then
#        message="$letter"
#    fi
#    message="$message$letter"
#done

echo -e "$message"

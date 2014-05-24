#!/bin/bash
#
# Morse Code Translator
# Bash(ncurses)
# Copyright (C) 2014 Ng Tzy Luen. All Rights Reserved.
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


string_to_morse_handler() {
    l=$(to_upper "$1")
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
    echo $morse_code_line
}

morse_to_string_handler() {
    morse_code_line="$1"
    declare -A morse_code_list=$(echo "$morse_code_line" | sed 's/  /\n/g')
    unset message
    for m in ${morse_code_list[@]}; do
        letter=$(to_letter $m)
        if [[ -z $letter ]]; then
            message="$letter"
        fi
        message="$message$letter"
    done
    echo $message
}


morse_gui() {
    form_field=$1
    cmd=(dialog --title "Morse code translator" --backtitle "Morse code translator" --form "$form_field:" 10 50 0)
    options=("$form_field" 1 1 "" 1 25 25 0)
    values=$("${cmd[@]}" "${options[@]}" 2>&1 1>&3)

    if [ "$form_field" = "String to morse" ]; then
        res=$(string_to_morse_handler "$values")
    elif [ "$form_field" = "Morse to string" ]; then
        res=$(morse_to_string_handler "$values")
    fi
    echo $res

    msgbox "$form_field" "$res"
}


msgbox() {
    dialog --title "$1" --clear --msgbox "$2" 10 50
}


exec 3>&1   #open fd

cmd=(dialog --title "Morse code translator" --backtitle "Morse code translator" --radiolist "Select one (and Enter):" 10 50 0)
options=(1 "String to morse" on
         2 "Morse to string" off)
mode=$("${cmd[@]}" "${options[@]}" 2>&1 1>&3)

if [ $mode -eq 1 ]; then
    morse_gui "String to morse"
elif [ $mode -eq 2 ]; then
    morse_gui "Morse to string"
fi

exec 3>&-   #close fd

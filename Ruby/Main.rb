# Morse Code Translator
# Ruby 
# Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
# 
# Notes:
# Tested under Ruby 1.9.3

require_relative 'Morse.rb'

morse_code_list = Array.new
while line = gets
    line.upcase.split("").each do |i|
    morse_code = Morse.get_morse(i)
    morse_code_list.push([i, morse_code])
    printf "%s ", morse_code
    end
    puts
end

morse_code_list.each {|c, morse_code| printf "%s", Morse.to_letter(morse_code)}
puts

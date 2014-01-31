# Morse Code Translator
# Ruby 
# Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
# 
# Notes:
# Tested under Ruby 1.9.3

class Morse
    @@morse_code_alpha_table = {:A=> ".-",    :B=> "-...",  :C=> "-.-.",
                                :D=> "-..",   :E=> ".",     :F=> "..-.",
                                :G=> "--.",   :H=> "....",  :I=> "..",
                                :J=> ".---",  :K=> "-.-",   :L=> ".-..",
                                :M=> "--",    :N=> "-.",    :O=> "---",
                                :P=> ".--.",  :Q=> "--.-",  :R=> ".-.",
                                :S=> "...",   :T=> "-",     :U=> "..-",
                                :V=> "...-",  :W=> ".--",   :X=> "-..-",
                                :Y=> "-.--",  :Z=> "--.."}

    @@morse_code_numeric_table = {:'0'=> "-----",  :'1'=> ".----",   :'2'=> "..---",
                                  :'3'=> "...--",  :'4'=> "....-",   :'5'=> ".....",
                                  :'6'=> "-....",  :'7'=> "--...",   :'8'=> "---..",
                                  :'9'=> "----.",  :'.'=> ".-.-.-",  :','=> "--..--",
                                  :'?'=> "..--..", :'"'=> ".----.",  :'!'=> "-.-.--",
                                  :'/'=> "-..-.",  :'('=> "-.--.",   :')'=> "-.--.-",
                                  :'&'=> ".-...",  :':'=> "---...",  :';'=> "-.-.-.",
                                  :'='=> "-...-",  :'+'=> ".-.-.",   :'-'=> "-....-",
                                  :'_'=> "..--.-", :'$'=> "...-..-", :'@'=> ".--.-."}

    def self.get_morse(c)
        k = :"#{c}"
        if @@morse_code_alpha_table.has_key?(k)
            return @@morse_code_alpha_table[k]
        elsif @@morse_code_numeric_table.has_key?(k)
            return @@morse_code_numeric_table[k]
        elsif c == "\\"
            return ".-..-."
        elsif c == " "
            return " "
        else 
            return ""
        end
    end


    def self.to_letter(s)
        @@morse_code_alpha_table.each{|key,value| return key if value == s}
        @@morse_code_numeric_table.each{|key,value| return key if value == s}
        return " " if s == " "
        return ""
    end
end

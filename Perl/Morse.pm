# Morse Code Translator
# Perl 
# Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
# 
# Notes:
# Tested under Perl v5.14.2

package Morse;
use strict;
use warnings;
our $VERSION = '1.00';
use base 'Exporter';
our @EXPORT = qw(get_morse to_letter);

my %morse_code_table = (A=>".-", B=>"-...", C=>"-.-.", D=>"-..",
                        E=>".", F=>"..-.", G=>"--.", H=>"....",
                        I=>"..", J=>".---", K=>"-.-", L=>".-..",
                        M=>"--", N=>"-.", O=>"---", P=>".--.",
                        Q=>"--.-", R=>".-.", S=>"...", T=>"-",
                        U=>"..-", V=>"...-", W=>".--", X=>"-..-",
                        Y=>"-.--", Z=>"--..",
                        '0'=>"-----", '1'=>".----", '2'=>"..---", '3'=>"...--",
                        '4'=>"....-", '5'=>".....", '6'=>"-....", '7'=>"--...",
                        '8'=>"---..", '9'=>"----.", '.'=>".-.-.-", ','=>"--..--",
                        '?'=>"..--..", '\''=>".----.", '!'=>"-.-.--", '/'=>"-..-.",
                        '('=>"-.--.", ')'=>"-.--.-", '&'=>".-...", ':'=>"---...",
                        ';'=>"-.-.-.", '='=>"-...-", '+'=>".-.-.", '-'=>"-....-",
                        '_'=>"..--.-", '"'=>".-..-.", '$'=>"...-..-", '@'=>".--.-.",
                        ' '=>" ", '\n'=>"\n");


sub get_morse {
    my $c = shift;
    return $morse_code_table{$c};
}

sub to_letter {
    my $morse_code = shift;
    my @matched = grep { $morse_code_table{$_} eq $morse_code } keys %morse_code_table;
    return shift @matched;
}

1;

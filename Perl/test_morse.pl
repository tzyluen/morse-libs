#!/usr/bin/perl
# Morse Code Translator
# Perl 
# Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
# 
# Notes:
# Tested under Perl v5.14.2

use strict;
use warnings;
use Morse;

my @morse_codes = [];
while (my $line = <STDIN>) {
    $line = uc($line);
    my @chars = split(//, $line);
    for my $c (@chars) {
        my $morse_code = &get_morse($c);
        if (defined $morse_code) {
            print $morse_code;
            push(@morse_codes, [$c, $morse_code]);
        }
    }
} print "\n";


for my $i (@morse_codes) {
    if (defined $$i[0]) {
        #print $$i[0];
        print &to_letter($$i[1]);
    }
} print "\n";

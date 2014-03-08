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
    my $morse_codes = &string_to_morse($line);
    print "$morse_codes\n";
    print &morse_to_string($morse_codes)."\n";
}

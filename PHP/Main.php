<?php
/**
  * Morse Code Translator
  * PHP 
  * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
  *
  * Notes:
  * Tested under PHP 5.4.4-14 CLI
  */
require 'Morse.php';

$line = trim(fgets(STDIN));
$morseCodeList = array();

foreach (str_split($line) as $c) {
    $morseCode = Morse::getMorse($c);
    array_push($morseCodeList, $morseCode);
    print $morseCode." ";
} print "\n";

foreach ($morseCodeList as $morseCode) {
    print Morse::toLetter($morseCode);
} print "\n";

?>

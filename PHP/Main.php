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
$morses = Morse::stringToMorse($line);
printf("%s\n", $morses);

$string = Morse::morseToString($morses);
printf("%s\n", $string);
?>

<?php
/**
  * Morse Code Translator
  * PHP 
  * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
  *
  * Notes:
  * Tested under PHP 5.4.4-14 CLI
  */

class Morse {
    private static $map = ['A'=>".-", 'B'=>"-...", 'C'=>"-.-.", 'D'=>"-..",
            'E'=>".", 'F'=>"..-.", 'G'=>"--.", 'H'=>"....",
            'I'=>"..", 'J'=>".---", 'K'=>"-.-", 'L'=>".-..",
            'M'=>"--", 'N'=>"-.", 'O'=>"---", 'P'=>".--.",
            'Q'=>"--.-", 'R'=>".-.", 'S'=>"...", 'T'=>"-",
            'U'=>"..-", 'V'=>"...-", 'W'=>".--", 'X'=>"-..-",
            'Y'=>"-.--", 'Z'=>"--..",
            '0'=>"-----", '1'=>".----", '2'=>"..---", '3'=>"...--",
            '4'=>"....-", '5'=>".....", '6'=>"-....", '7'=>"--...",
            '8'=>"---..", '9'=>"----.", '.'=>".-.-.-", ','=>"--..--",
            '?'=>"..--..", '\''=>".----.", '!'=>"-.-.--", '/'=>"-..-.",
            '('=>"-.--.", ')'=>"-.--.-", '&'=>".-...", ':'=>"---...",
            ';'=>"-.-.-.", '='=>"-...-", '+'=>".-.-.", '-'=>"-....-",
            '_'=>"..--.-", '"'=>".-..-.", '$'=>"...-..-", '@'=>".--.-.",
            '\n'=>"\n"];


    public static function getMorse($c) {
        return (isset(self::$map[$c])) ? self::$map[$c] : "";
    }


    public static function toLetter($s) {
        $umap = array_flip(self::$map);
        return (isset($umap[$s])) ? $umap[$s] : "";
    }


    public static function stringToMorse($s) {
        $s = strtoupper($s);
        $morses = "";
        foreach (str_split($s) as $c) {
            $morseCode = self::getMorse($c);
            $morses .= $morseCode." ";
        }
        return $morses;
    }


    public static function morseToString($s) {
        $string = "";
        $_s = preg_split("/\s{2}/", $s);
        foreach ($_s as $__s) {
            $mc = preg_split("/\s{1}/", $__s);
            foreach ($mc as $_mc) {
                $string .= self::toLetter($_mc);
            }
            $string .= " ";
        }
        return $string;
    }
}?>

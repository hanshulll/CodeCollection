<?php

function checkPalindrome($text) {
    return strrev($text) === $text;
}

$text = 'level';

if(checkPalindrome($text)) {
    echo "$text is palindrome" . PHP_EOL;
} else {
    echo "$text is not palindrome" . PHP_EOL;
}
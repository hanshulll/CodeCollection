<?php

$mystring = 'abcdefgijk';
$findme   = 'a';
$pos = strpos($mystring, $findme);

// Note the use of ===. Since simple == will not work as expected
// because the position of 'a' is in the 1st (first) character.
if ($pos === false) {
    echo "The chain '$findme' was not found in the chain '$mystring'";
} else {
    echo "The chain '$findme' was found in the '$mystring'";
    echo " and exists in the position $pos";
}

?>
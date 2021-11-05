<?php

function factorial( $n ) {

  if ( $n == 0 ) {
    echo "Base case: $n = 0. Returning 1...<br>";
    return 1;
  }

  echo "$n = $n: Computing $n * factorial( " . ($n-1) . " )...<br>";
  $result = ( $n * factorial( $n-1 ) );
  echo "Result of $n * factorial( " . ($n-1) . " ) = $result. Returning $result...<br>";
  return $result;
}

echo "The factorial of 5 is: " . factorial( 5 );

?>

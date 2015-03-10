#!/bin/bash
for (( i = 1; i <= 256; i *= 2 )); do
  echo "key length = $i"
  echo "Cipher Summary"
  echo ""
  for (( j = 1; j < 256; j *= 2 )); do
    echo "detect key length: $j"
    ./vigenere_encrypt $i plaintext | ./summary | ./icanalyze $j
    echo ""
  done
done

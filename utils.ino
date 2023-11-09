void print_bin(byte num) {
  for (int8_t aBit = 7; aBit >= 0; aBit--) {
    Serial.write(bitRead(num, aBit) ? '1' : '0');
  }
  Serial.println();
}

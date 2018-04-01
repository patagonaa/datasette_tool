# data to audio en-/decoder (datasette-like)

## Usage:
cat /usr/share/dict/words | ./encoder.out > out.raw
cat out.raw | ./decoder.out 2> /dev/null
(default format: unsigned 8-bit mono, 48000Hz)

## Compile with:
```c
make
```

# data to audio en-/decoder (datasette-like)

## Usage:
Encoder expects data on stdin, outputs raw unsigned 8-bit mono 48000Hz audio samples on stdout.
Decoder expects samples on stdin, outputs data on stdout.

Example:
```c
cat /usr/share/dict/words | ./encoder.out > out.raw
cat out.raw | ./decoder.out 2> /dev/null
```
(default format: unsigned 8-bit mono, 48000Hz)

## Compile with:
```c
make
```

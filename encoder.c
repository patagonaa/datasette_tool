#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<stdbool.h>

#define PI 3.14159265

void output_bit(bool bit);

const uint32_t sampleRate = 48000; // Hz
const uint16_t frequency1 = 1000; // Hz
const uint16_t frequency2 = 2000; // Hz

int main(){
	for(int i = 0; i < 1000*8; i++){
		output_bit(false);
	}
	for(int i = 0; i < 8; i++){
		output_bit(true);
	}
	int chr;
	while((chr = getchar()) != EOF){
		for(int bit = 0; bit < 8; bit++){
			bool data_bit = chr & (1 << bit);
			output_bit(data_bit);
		}
	}
}

void output_bit(bool bit){
	uint16_t frequency = bit ? frequency1 : frequency2;
	for(double j = 0; j < 1; j += 1.0 / ((double)sampleRate / frequency)){
		int8_t sample = sin(j * (2*PI)) * 127;
		putchar((unsigned char) sample + 128);
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>
#include<stdbool.h>

#define PI 3.14159265

int8_t input_bit();
uint16_t get_cycle_freq();

const uint32_t sampleRate = 48000; // Hz
const uint16_t frequency1 = 1000; // Hz
const uint16_t frequency2 = 2000; // Hz
const uint16_t freq_thresh = 500; // Hz
const uint8_t zero_thresh = 10;

int main(){
	while(input_bit() != 0);
	for(int i = 0; i < 7; i++){
		int8_t bit = input_bit();
		if(bit != 0)
			fprintf(stderr, "start mark corrupt!\n");
	}
	int8_t bit;
	unsigned char read_char = 0;
	uint8_t byte_part = 0;
	while((bit = input_bit()) != -1){
		read_char |= (bit ? 0 : 1) << byte_part;
		if(byte_part == 7){
			putchar(read_char);
			byte_part = 0;
			read_char = 0;
		}else{
			byte_part++;
		}
	}
}


int8_t input_bit(){
	uint16_t freq = get_cycle_freq();
	fprintf(stderr, "Frequency: %dHz \n", freq);
	if(abs(freq - frequency1) < freq_thresh)
		return 0;
	if(abs(freq - frequency2) < freq_thresh)
		return 1;
	fprintf(stderr, "Invalid Frequency: %dHz \n", freq);
	return -1;
}

uint16_t get_cycle_freq(){
	int chr;
	bool neg_half_cycle = false;
	uint32_t sample_count = 0;
	while((chr = getchar()) != EOF){
		int8_t sample = chr - 128;
		if(neg_half_cycle && sample > zero_thresh){
			uint16_t freq = sampleRate / sample_count;
			return freq;
		}
		if(sample < -zero_thresh)
			neg_half_cycle = true;
		sample_count++;
	}
	return 0;
}

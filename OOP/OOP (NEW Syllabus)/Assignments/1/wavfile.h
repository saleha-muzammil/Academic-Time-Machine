//code modified from: http://stackoverflow.com/questions/13660777/c-reading-the-data-part-of-a-wav-file
#ifndef WAVFILE_H
#define WAVFILE_H

//read wav file.  You have to specify the filename
//the function will read the audio signal in data.  length is an input output parameter
//if you specify a length less than the size of the array, length items would be read from the audio file
//if length is more than the size of the file, then only the number of bytes contained in the audio file
//would be read and the number of bytes read would be returned in length
//the function also returns the sampling rate in the parameter samplingRate
//The return value of the function is true for successful reading of audio file and false otherwise
//NOTE: Will only read audio files which are mono wav files and stored at 8 bits per sample
bool readWavFile(char *fileName, unsigned char data[],int &length,int &samplingRate);

//write data to a wav file by specifying the name of the file, the unsigned char array
//and the current size of the array and also the sampling rate.  The sampling rate you can get
//by reading the wav file or you could specify your own, e.g., 8000.
//the function returns true on successful write and false otherwise
bool writeWavFile(char *fileName, unsigned char data[],int length,int samplingRate);

//play wav file.  You have to specify the filename 
//If file exist on the path provided as file name then play the file and return true
//Otherwise return false.
bool playWavFile(char *fileName);


#endif
//code modified from: http://stackoverflow.com/questions/13660777/c-reading-the-data-part-of-a-wav-file
//wav file from: https://aacapps.com/lamp/voices

#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include "wavfile.h"
#include <fstream>
#pragma comment(lib, "Winmm.lib")
using namespace std;

typedef struct  WAV_HEADER
{
    char                RIFF[4];        // RIFF Header      Magic header
    unsigned long       ChunkSize;      // RIFF Chunk Size  
    char                WAVE[4];        // WAVE Header      
    char                fmt[4];         // FMT header       
    unsigned long       Subchunk1Size;  // Size of the fmt chunk                                
    unsigned short      AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM 
    unsigned short      NumOfChan;      // Number of channels 1=Mono 2=Sterio                   
    unsigned long       SamplesPerSec;  // Sampling Frequency in Hz                             
    unsigned long       bytesPerSec;    // bytes per second 
    unsigned short      blockAlign;     // 2=16-bit mono, 4=16-bit stereo 
    unsigned short      bitsPerSample;  // Number of bits per sample      
    char                Subchunk2ID[4]; // "data"  string   
    unsigned long       Subchunk2Size;  // Sampled data length    

} wav_hdr; 

void constructHeader(wav_hdr &wavHeader,int length,int rate=8000)
{
	wavHeader.RIFF[0] = 'R';wavHeader.RIFF[1] = 'I';wavHeader.RIFF[2] = 'F';wavHeader.RIFF[3] = 'F';
	wavHeader.ChunkSize = length+sizeof(wavHeader)-8;
	wavHeader.WAVE[0] = 'W';wavHeader.WAVE[1] = 'A';wavHeader.WAVE[2] = 'V';wavHeader.WAVE[3] = 'E';
	wavHeader.fmt[0] = 'f';wavHeader.fmt[1] = 'm';wavHeader.fmt[2] = 't';wavHeader.fmt[3] = ' ';
	wavHeader.Subchunk1Size = 16;
	wavHeader.AudioFormat = 1;
	wavHeader.NumOfChan = 1;
	wavHeader.SamplesPerSec = rate;
	wavHeader.bytesPerSec = rate;
	wavHeader.blockAlign = 1;
	wavHeader.bitsPerSample = 8;
	wavHeader.Subchunk2ID[0] = 'd';	wavHeader.Subchunk2ID[1] = 'a';	wavHeader.Subchunk2ID[2] = 't';	wavHeader.Subchunk2ID[3] = 'a';
	wavHeader.Subchunk2Size = length;
}


// Function prototypes 
int getFileSize(FILE *inFile); 

bool readWavFile(char *fileName,unsigned char data[],int &length,int &samplingRate)
{
    FILE *wavFile;
    int headerSize = sizeof(wav_hdr),filelength = 0;
	bool success=false;
    wavFile = fopen( fileName , "r" );
	wav_hdr wavHeader;
	if (wavFile)
	{
		fread(&wavHeader,headerSize,1,wavFile);
		if (wavHeader.Subchunk2Size < length)
			length = wavHeader.Subchunk2Size;
		
		cout << "Total Length of File : " << wavHeader.Subchunk2Size << endl;
		cout << "Bits per sample: " << wavHeader.bitsPerSample <<endl;
		cout << "Data Rate BytesPerSec: " << wavHeader.bytesPerSec << endl;
		cout << "Num Of Chanels: " << wavHeader.NumOfChan << endl;
		cout << "Sample Rate: " << wavHeader.SamplesPerSec << endl;

		fread(data,length,1,wavFile);
		filelength = getFileSize(wavFile);
		fclose(wavFile);
		samplingRate = wavHeader.SamplesPerSec;
		success = true;
	}
    return success;
} 
// find the file size 
int getFileSize(FILE *inFile)
{
    int fileSize = 0;
    fseek(inFile,0,SEEK_END);

    fileSize=ftell(inFile);

    fseek(inFile,0,SEEK_SET);
    return fileSize;
}

bool writeWavFile(char *fileName, unsigned char data[],int length,int samplingRate)
{
    FILE *wavFile;
	bool success = false;
	wav_hdr wavHeader;
	constructHeader(wavHeader,length,samplingRate);
	wavFile = fopen(fileName,"w");
	if (wavFile)
	{
		fwrite(&wavHeader,sizeof(wavHeader),1,wavFile);
		fwrite(data,length,1,wavFile);
		fclose(wavFile);
		success = true;
	}
	return success;
}

bool playWavFile(char* fileName) {
	FILE* wavFile;
	wavFile = fopen(fileName, "r");
	if (wavFile)
	{
		fclose(wavFile);
		WCHAR wstr[100] = {};
		for (int i = 0; i < 20 && fileName[i]; ++i)
			wstr[i] = fileName[i];

		bool stop = 0;
		cout << "Now Playing:  " << fileName << endl;
		PlaySound(wstr, NULL, SND_LOOP | SND_ASYNC);
		cout << "Enter 1 to Stop: ";
		while (!stop) {
			cin >> stop;
			PlaySound(NULL, 0, 0);
		}
		cout << "Stopped!" << endl;
		return true;
	}
	else {
		return false;
	}
}

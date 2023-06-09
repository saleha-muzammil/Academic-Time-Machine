#include<iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<unistd.h>
#include<fstream>
#include<string>
#include<queue>
#include <mutex>
using namespace std;

//It contains eithers 1 or 2 
//if it is 1 it mean it is process 1 else process 2
//it is set from the input of user
int processid = 1;
mutex _mutex;


int main(int argc, char** argv) {
    
    
    //Taking input from user about process no (1 or 2)
    char isProcess1 = 'n';
    cout<<"Is it process 1   (Enter y or n)  = ";
    cin>>isProcess1;
    if(isProcess1 == 'y' || isProcess1 == 'Y')
        processid = 1;
    else 
        processid = 2;
    
    
    //Making queue of lines of input files
    //Queue is used because we can then pop item one by one and process it.
    queue<string> fileLinesQueue;
    string fileLine; 
    ifstream infile;
    infile.open("InputAssign-1.txt");
    while(getline(infile,fileLine))
    {
        fileLinesQueue.push(fileLine);
    }
    infile.close();       
    
    
    
    //setting first line for process name
    string processNameLine =fileLinesQueue.front();fileLinesQueue.pop();
    
    if(processid == 1)
      processNameLine = processNameLine.substr(0,processNameLine.find(',')); 
    else 
      processNameLine = processNameLine.substr(processNameLine.find(',')+1,(processNameLine.length()-1));
     
       ofstream myfile (processNameLine+".txt"); 
    
       //creating shared memory area
       char c;
       int shmid;
       key_t key;    
       char *shm,*s;

       key = 5679;

       // Create the segment.       
       if ((shmid = shmget(key, 1, IPC_CREAT | 0666)) < 0) {
               cerr<<"shmget";
               exit(1);
       }

       //Now we attach the segment to our data space.      
       if ((shm = (char *)shmat(shmid, 0, 0)) == (char *) -1) 
       {
               cerr<<"shmat";
               exit(1);
       }

       s = shm;
       
       /*
        *Shared memory first two cells are specified for specifical purpose so two process can communicate easily
        *Cell 1 = It can contain either *, 1, 2, 3, 4
        *   * =  If first cell has value * , it mean any process can occupy shared memory and write in it.
        *   1 =  process 1 , will set 1 if it wants to write in shared memory.        * 
        *   2 =  process 2 , will set 2 if it wants to write in shared memory.
        *   3 =  process 2 , will write 3 after completing write operation in shared memory   
        *   4 =  process 1 , will write 4 after completing write operation in shared memory
        
        */
       if(processid == 1)
       {
          *s = '*';
          *(s + 1) = 0;
       }
        
       
    //no. of times iterate depend on items count in file   
    while(fileLinesQueue.size() > 0)
    {           
                                  
        //reading line from queue and splitting based on ,         
        string lineData = "";
        if(processid == 1)
            lineData =   fileLinesQueue.front().substr(0,fileLinesQueue.front().find(','));
        else             
            lineData =  fileLinesQueue.front().substr(fileLinesQueue.front().find(',')+1,(fileLinesQueue.front().length()-1));
        
        const char* t = " \t\n\r";
        lineData = lineData.erase(0,lineData.find_first_not_of(t));
      
        sleep(2);
      
       //2 types of line if it start with [ it will write in other process file else in same     
        if(lineData.find_first_of("[") == 0)
        {        
             //wait process 1 is writing in shared memory
        if(processid == 2)
             while(*s == '1')
                    sleep(1);  
                
         //wait process 2 is writing in shared memory     
        if(processid == 1)
                while(*s == '2')
                    sleep(1); 
        
        
        
             //read from shared memory 
            shm = s;
            shm++;
            if(processid ==1 &&   *s == '3')
            {
                while(1)
                {
                shm++;
                char o = *(shm);
                if(o==']')
                {
                    shm = s;
                    *s = '*';
                   cout<<"]"<<endl;
                    myfile<<"]"<<'\n';
                     _mutex.lock();                    
            *(s+1) += 1;
              if(*(s+1) % 2 == 0)
                          *(s+1) = 0;
            _mutex.unlock();
                  
                    break;
                }                
                else if(o == '[')
                {
                    cout<<"[";
                    myfile <<"[";
                    continue;
                }
                
                cout<<o;
                myfile <<o;
                }                
            }
            
            //if process 2 need to read data from shared memory
            else if(processid ==2 &&   *s == '4')
            {
                while(1)
                {
                shm++;
                char o = *(shm);
                if(o==']')
                {
                    shm = s;
                    *s = '*';
                    
                    
                    cout<<"]"<<endl;
                    myfile<<"]"<<'\n';
                      _mutex.lock();                    
            *(s+1) += 1;
              if(*(s+1) % 2 == 0)
                          *(s+1) = 0;
            _mutex.unlock(); 
                   
                    break;
                }                
                else if(o == '[')
                     {
                    cout<<"[";
                    myfile <<"[";
                    continue;
                }
                
                cout<<o;
                 myfile <<o;
                }                
            } 
            
             //no one is using shared memory so any one can write it after getting access
            if( *s == '*'  || *s == ' ')
            {
                
                  shm = s;
                if(processid == 1)
                    *s = '1';
                else 
                    *s = '2';
                  
                    shm++;
                for(int i=0;i<lineData.length();i++)
                {
                    shm++;
                   *(shm) = lineData[i];
                }
                if(processid == 1)
                {
                    *s ='4';
                }
                else 
                {
                    *s ='3';
                }                    
                shm = s;
               
            }   
            
            
            
            
            
                    //process 1 is waiting for process 2 to read from shared memory
        if(processid == 1)
             while(*s == '4')
                    sleep(1);  
                
         //process 2 is waiting for process 1 to read from shared memory       
        if(processid == 2)
                while(*s == '3')
                    sleep(1);  
          
                
        }
        else
        {
            cout<<lineData<<endl;
            myfile<<lineData<<"\n";
            
            
            _mutex.lock();                    
            *(s+1) += 1;
              if(*(s+1) % 2 == 0)
                          *(s+1) = 0;
            _mutex.unlock();
            
         
        }
        
       //this will make sure each process execute its 1 command then move to next line
        while(*(s+1) % 2 != 0)
        {
         shm = s;
            shm++;
            if(processid ==1 &&   *s == '3')
            {
                while(1)
                {
                shm++;
                char o = *(shm);
                if(o==']')
                {
                    shm = s;
                    *s = '*';
                  cout<<"]"<<endl;
                    myfile<<"]"<<'\n';
                        _mutex.lock();                    
            *(s+1) += 1;
              if(*(s+1) % 2 == 0)
                          *(s+1) = 0;
            _mutex.unlock(); 
                  
                    break;
                }                
                else if(o == '[')
                     {
                    cout<<"[";
                    myfile <<"[";
                    continue;
                }
                
                cout<<o;
                myfile <<o;
                }                
            }
            
            //if process 2 need to read data from shared memory
            else  if(processid ==2 &&   *s == '4')
            {
               
                while(1)
                {
                shm++;
                char o = *(shm);
                if(o==']')
                {
                    shm = s;
                    *s = '*';
                   cout<<"]"<<endl;
                    myfile<<"]"<<'\n';
                       _mutex.lock();                    
            *(s+1) += 1;
              if(*(s+1) % 2 == 0)
                          *(s+1) = 0;
            _mutex.unlock();
            
                   
                    break;
                }                
                else if(o == '[')
                     {
                    cout<<"[";
                    myfile <<"[";
                    continue;
                }
                
                cout<<o;
                 myfile <<o;
                }                
            } 
        }

        fileLinesQueue.pop();
       
      
        
    }  
       myfile.close();
       int close = 0;
       cout<<"\n\n\nPress any key to close";
       cin>>close;
       
       exit(0);
}


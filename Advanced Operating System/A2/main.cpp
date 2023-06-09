
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <sstream>

using namespace std;
        char * readBuf= new char [10000];
        int * pBuf = new int [10000];
        int * Slines = new int [10000];
        int * Elines = new int[10000];
        int * ExeT= new int[10000];
        int  * AT = new int[10000];
        int * Th = new int[10000];
        int * proc= new int[10000];
        int * temp = new int[100];
        int * Dlines = new int[10000];
        int c=0; int c1=0; int len=0;
        int Core1=0;int Core2=0;
        int p1=0;int p2=0;
        int p1t=0;int p2t=0;
        int count=0;int th1c=0; int th2c=0;
        
        string inToString(int i){stringstream s;s<<i;return s.str();}
        int choose(int * temp,int * Dl, int time,int len)
        { 
            int  min = temp[0];
            int loc= temp[0];
             for ( int c = 1 ; c < len ; c++ ) 
             {
                   if(time>Dl[min]){min=temp[c];loc=temp[c];}
               else {
                   if(Dl[min]>Dl[temp[c]]&&time<Dl[temp[c]]){min=temp[c];loc=temp[c];}
               }
             }
             return loc;
        }
        int dup(int * AT,int time,int index)
        {
            int j=0;
            for(int i=index; i<count;i++){
                if(AT[i]<=time&&Dlines[i]>=time+ExeT[i]&&Th[i]>=1&&Th[i]<=5){temp[c1++]=i;}
            }
            int i=0;
             len=c1;
             c1=0;
             if(len==0){return 0;}
             else {return choose(temp,Dlines,time,len);}
        
        }
        int dup1(int * AT,int time,int index)
        {
            int j=0;
            for(int i=index; i<count;i++){
                if(AT[i]<=time&&Dlines[i]>time&&Th[i]>=1&&Th[i]<=5){temp[c1++]=i;}
            }
            int i=0;
             len=c1;
             c1=0;
             if(len==0){return 0;}
             else {return choose(temp,Dlines,time,len);}
        
        }
        void Swap(int i, int p){
            int temp=Dlines[p];
            int temp1= AT[p];
            int  temp2=ExeT[p];
            int temp3=Th[p];
            int temp4= proc[p];
            Dlines[p]=Dlines[i];
            AT[p]=AT[i];
            ExeT[p]=ExeT[i];
            Th[p]=Th[i];
            proc[p]=proc[i];
            Dlines[i]=temp;
            AT[i]=temp1;
            ExeT[i]=temp2;
            Th[i]=temp3;
            proc[i]=temp4;
            
        }
 

int main(void)
{ 
   
       std::string str ("idle");
       std::string strC1 ("CPU1");
       std::string strC2("CPU2");
       std::string tstr ("Context Switch Time");
       std::ifstream infile ("Input2.txt");
       std::ofstream outfile("outputAssign-2.txt");
        // size of file
        infile.seekg (0,infile.end);
        long size = infile.tellg();
        
        infile.seekg (0);
        int a=0;
        //copying file contents
        infile.read(readBuf,size);
     
        for(int i=0; i<size; i++){
            char * str1 = new char[10];
            while(readBuf[i]!=','){ str1[c1++]=readBuf[i++];}
               a=atoi(str1);
                proc[c]=a;
                strcpy(str1,"");
                i++;c1=0;
            while(readBuf[i]!=','){ str1[c1++]=readBuf[i++];}
                a=atoi(str1);
                Th[c]=a;
                i++;c1=0;
                 strcpy(str1,"");
            while(readBuf[i]!=','){ str1[c1++]=readBuf[i++];}
                a=atoi(str1);
                AT[c]=a;
                c1=0;i++;strcpy(str1,"");
            while(readBuf[i]!=','){ str1[c1++]=readBuf[i++];}
                a=atoi(str1);
                ExeT[c]= a;
                c1=0; 
                i++;
                strcpy(str1,"");
           if(readBuf[i]=='N'){ 
                    Slines[c]= 0;
                     while(readBuf[i]!=','){i++;}i++;
                     while(readBuf[i]!='\n'){str1[c1++]=readBuf[i++];}
                     a=atoi(str1);
                     Elines[c]=a;c1=0; strcpy(str1,"");}
           else{
                  while(readBuf[i]!=','){str1[c1++]=readBuf[i++];}      
                  a=atoi(str1);
                  Slines[c]=a;
                  Elines[c]=0;
                  i++;  
                  c1=0;
                  strcpy(str1,"");
               }
             c++;count++;
             while(readBuf[i]!='\n'){i++;}
             cout<<endl;
            
        } 
        
        //Calculating Ending Deadlines 
        for(int i=0; i<c;i++){
            if(Slines[i]!=0){Dlines[i]=Slines[i]+ExeT[i];}
            else{Dlines[i]=Elines[i];} 
            cout<<Dlines[i]<<"   ";
        }
        cout<<count;
        c1=0;
        c=0;
        int pp2=0;
        int time=0;
        int prevTime=0;
        int t1=0;
        int t2=0;
        int length=0;int e=0;
        //schedule generation
        for(int i=0; i<count; i++){
            if(Dlines[i]>time){
                if(Th[i]>=1&&p2!=proc[i]){th1c=0;th2c=0;}
                while(Th[i]<=5&& Th[i]>0){
                    prevTime=time;
                    if(Core1==0&&Core2==0){
                        if(Th[i] == 1&&AT[i+1]>time){
                            Th[i]= Th[i]-1;
                            th1c++;
                            pBuf[c++]=proc[i];
                            pBuf[c++]=th1c;
                            pBuf[c++]=0;
                            pBuf[c++]=time;
                            t1=time;
                            p1t=ExeT[i]+t1-prevTime;
                            time=time+p1t;
                            Core1=1;
                            p1=proc[i];
                        }else if(Th[i] >=2&&AT[i+1]>time+ExeT[i]){
                            Th[i]= Th[i]-1;
                            th1c++;
                            pBuf[c++]=proc[i];
                            pBuf[c++]=th1c;
                            Th[i]= Th[i]-1;
                            th2c=th1c+1;
                            pBuf[c++]=proc[i]; 
                            pBuf[c++]=th2c;
                            pBuf[c++]=time;   
                            Core1=1;t1=time;t2=time;
                            Core2=1;p1=proc[i];p2=proc[i];
                            p1t=ExeT[i]+t1-prevTime;
                            p2t=ExeT[i]+t2-prevTime;
                            time=time+p1t;
                        }else if(AT[i+1]<time+ExeT[i]){
                             if(time<AT[i+1]){
                                        int p=dup1(AT,time+ExeT[i],i+1);
                                        Swap(i+1,p);
                                        if(Dlines[i]>Dlines[i+1]){
                                             Th[i]= Th[i]-1;
                                             th1c++;
                                             pBuf[c++]=proc[i];
                                             pBuf[c++]=th1c;
                                             pBuf[c++]=0;
                                             pBuf[c++]=time;
                                             t1=time;
                                             time=AT[i+1];
                                             p1t=ExeT[i]+t1-prevTime;
                                             Core1=1;
                                             p1=proc[i];    
                                        }else{
                                                if(Th[i]>=2){
                                                        Th[i]= Th[i]-1;
                                                        pBuf[c++]=proc[i];
                                                        th1c=th2c;
                                                        pBuf[c++]=++th1c;
                                                        Th[i]= Th[i]-1;
                                                        th2c=th1c+1;
                                                        pBuf[c++]=proc[i]; 
                                                        pBuf[c++]=th2c; 
                                                        pBuf[c++]=time; 
                                                        Core1=1;Core2=1;
                                                        t1=time;t2=time;
                                                        p1t=ExeT[i]+t1-prevTime;
                                                        p2t=ExeT[i]+t1-prevTime;
                                                        time=p1t+time;
                                                        p1=proc[i];
                                                        p2=proc[i];
                    
                                                }else if(Th[i] ==1){
                                                        Th[i]= Th[i]-1;
                                                        th1c++;
                                                        pBuf[c++]=proc[i];
                                                        pBuf[c++]=th1c;
                                                        pBuf[c++]=0;
                                                        pBuf[c++]=time; 
                                                        t1=time;
                                                        p1t=ExeT[i]+t1-prevTime;
                                                        time=time+p1t;
                                                        Core1=1;p1=proc[i];
                                                        
                                                    }
                                                }
                                                   
                             }else if(time>=AT[i+1]){
                               
                          int p = dup(AT,time,i);
                          
                          Swap(i,p);
                         if(Th[i]==1){
                             if(time==t1+ExeT[i]&&e==1){Th[i]=Th[i]-1;}
                             else{
                                 e=1;
                              if(p2==proc[i]){th1c=th2c;}
                              if(p1!=proc[i]){th1c=0;}
                              th1c++;
                              pBuf[c++]=proc[i];
                              pBuf[c++]=th1c;
                              Core1=1;
                              t1=time;
                              int a= dup(AT,time,i+1);
                              if(a>0){
                              Swap(i+1,a);
                              Th[i+1]=Th[i+1]-1;th2c=0;
                              th2c++;
                              pBuf[c++]=proc[i+1];
                              pBuf[c++]=th2c;
                              Core2=1;
                              t2=time;
                              pBuf[c++]=time;
                              p1t=ExeT[i]+t1-prevTime;
                              p2t=ExeT[i+1]+t2-prevTime;
                              if(p1t<=p2t){time=time+p1t;Th[i]=Th[i]-1;}
                              else if(p1t>p2t){time=time+p2t;}
                              if(p1t<=p2t){Th[i]= Th[i]-1;}
                              p1=proc[i];
                              p2=proc[i+1];
                              }  
                              
                              else{pBuf[c++]=0;pBuf[c++]=time;p1t=ExeT[i]+t1-prevTime; time=time+p1t;p1=proc[i];Th[i]=Th[i]-1;}
                             }
                         }else if(Th[i]>=2){
                             Th[i]=Th[i]-1;
                            pBuf[c++]=proc[i];
                            if(p2==proc[i]){th1c=th2c;}
                            else if(p2!=proc[i]){th1c=0;th2c=0;}
                             pBuf[c++]=++th1c;
                            Th[i]=Th[i]-1;
                            pBuf[c++]=proc[i];
                            th2c=th1c+1;
                            pBuf[c++]=th2c;  
                            pBuf[c++]=time; 
                            Core1=1;Core2=1;t1=time;t2=time;
                            p1t=ExeT[i] +t1-prevTime;p2t=ExeT[i]+t2-prevTime;
                            time=time+p1t;
                            p1=proc[i];p2=proc[i];
                         
                         }
                       }
                    }
                        
                   
                
                }else if(Core1==1||Core2==1){
                   
                    if(Core1==1&&Core2==0){
                        if(time>=AT[i+1]){
                           if(Th[i]==1&&time==t1+ExeT[i]){Th[i]=Th[i]-1;}
                           else{
                           int p = dup(AT,time,i+1); 
                           if(p>0){
                           Swap(i+1,p);
                           Th[i+1]= Th[i+1]-1;
                           pBuf[c++]=proc[i];
                           pBuf[c++]=th1c;
                           pBuf[c++]=proc[i+1];
                           if(p2!=proc[i+1]){th2c=0;}
                           pBuf[c++]=++th2c;
                           pBuf[c++]=time;
                           Core2=1;
                           t2=time;
                           p2t=ExeT[i+1]+t2-prevTime;
                           p1t=ExeT[i]+t1-prevTime;
                           if(p1t<=p2t){time= time+p1t;}
                           else if(p2t<p1t){time= time+p2t;}
                           p1=proc[i];
                           p2=proc[i+1];
                           pp2=p2;
                           }
                           else{pBuf[c++]=proc[i];pBuf[c++]=th1c;pBuf[c++]=0;pBuf[c++]=time;
                           p1t=ExeT[i]+t1-prevTime;time=time+p1t;}
                           }
                        }else{
                           if(Th[i]>=1){
                               pBuf[c++]=proc[i];
                               pBuf[c++]=th1c;
                               pBuf[c++]=proc[i];
                               pBuf[c++]=++th1c;
                               pBuf[c++]=time;
                               t2=time;
                               p1=proc[i];
                               p2=proc[i];
                               p1t=ExeT[i]+t1-prevTime;
                               p2t=ExeT[i]+t2-prevTime;
                               Th[i]=Th[i]-1;
                               if(p1t<=p2t){time= time+p1t;}
                               else if(p2t<p1t){time= time+p2t;}
                               
                            }else{
                           pBuf[c++]=proc[i];
                           pBuf[c++]=th1c;
                           pBuf[c++]=0;
                           pBuf[c++]=time;
                           p1=proc[i];
                           p1t=ExeT[i]+t1-prevTime;
                           Th[i]=Th[i]-1;
                           time=time+p1t;
                       }
                     } 
                    
                    }else if(Core1==0&&Core2==1){
//                        if(Dlines[i]>time){
                        if(Th[i]>=2&&p2==proc[i]&&Dlines[i]>time+ExeT[i]){
                             th1c=th2c;
                             Th[i]= Th[i]-1;
                             pBuf[c++]=proc[i];
                             pBuf[c++]=++th1c;
                             pBuf[c++]=proc[i];
                             pBuf[c++]=th2c;
                             pBuf[c++]=time;
                             Core1=1;
                             t1=time;
                             p1t=ExeT[i]+t1-prevTime;
                             p2t=ExeT[i]+t2-prevTime;
                             if(p1t<=p2t){time= time+p1t;}
                             else if(p2t<p1t){time= time+p2t;}
                             p1=proc[i];
                             p2=proc[i];
                        }   
                        else if(Th[i]==1&&p2==proc[i]&&Dlines[i]>time+ExeT[i]){
                            if(time==t1+ExeT[i]){Th[i]=Th[i]-1;}
                            else{
                            th1c=th2c;
                             pBuf[c++]=proc[i];
                             pBuf[c++]=++th1c;
                             pBuf[c++]=proc[i];
                             pBuf[c++]=th2c;
                             pBuf[c++]=time;
                             Core1=1;
                             t1=time;
                             p1t=ExeT[i]+t1-prevTime;
                             p2t=ExeT[i]+t2-prevTime;
                             if(p1t<=p2t){time= time+p1t;}
                             else if(p2t<p1t){time= time+p2t;}
                             
                             p1=proc[i];
                             p2=proc[i];
//                         }
                        }//else if(Th[i]==1&&time==t1+ExeT[i]){Th[i]=Th[i]-1;}
                        
                        
                        
                        }  else if(Th[i]>=1&&p2!=proc[i]&&Dlines[i]>time+ExeT[i]){
                           //if(Th[i]==1&&time==ExeT[i]+t1){Th[i]=Th[i]-1;}
                           //else{
                            //cout<<proc[i];
                             Th[i]=Th[i]-1;
                             pBuf[c++]=proc[i];
                             pBuf[c++]=++th1c;
                             pBuf[c++]=p2;
                             pBuf[c++]=th2c;
                             pBuf[c++]=time;
                             Core1=1;
                             t1=time;
                             p1t=ExeT[i]+t1-prevTime;
                             p2t=ExeT[i+1]+t2-prevTime; cout<<time<<endl;
                             if(p1t<=p2t){time= time+p1t;}
                             else if(p2t<p1t){time= time+p2t;}
                             p1=proc[i];
                              p2=proc[i+1];
                             
                           // }
                        }  

                    else{
                            int p=dup(AT,time,i);
                            if(p>0){
                            Swap(p,i);
                            Th[i]=Th[i]-1;
                            pBuf[c++]=proc[i];
                            if(p2!=proc[i]){th1c=0;}
                            if(p2==proc[i]){th1c=th2c;}
                            t1=time;
                            p1t=ExeT[i]+t1-prevTime;
                            if(th1c!=0){p2t=ExeT[i]+t2-prevTime;}
                            else{p2t=ExeT[i+1]+t2-prevTime;}
                            pBuf[c++]=++th1c;
                            pBuf[c++]=p2;
                            pBuf[c++]=th2c;
                            pBuf[c++]=time;
                            Core1=1;
                            
                            if(p1t<=p2t){time= time+p1t;}
                            else if(p2t<p1t){time= time+p2t;}
                                p1=proc[i];
                            }
                            else{pBuf[c++]=0;
                                 pBuf[c++]=p2;
                                 pBuf[c++]=th2c;
                                 pBuf[c++]=time;
                                 time= time+p2t;
                           }      
                        
                } 
              }
              }
             
                if(Core1==1&&Core2==0&&time==p1t+prevTime){
                    pBuf[c++]=p1;pBuf[c++]=th1c;pBuf[c++]=0;pBuf[c++]=time;
                    Core1=0;//p1t=0;t1=0;
                    
                }
                else if(Core1==0&&Core2==1&&time==p2t+prevTime){
                  pBuf[c++]=0;pBuf[c++]=p2;pBuf[c++]=th2c;pBuf[c++]=time;
                  Core2=0;//p2t=0;t2=0;
               }
               
                else if(Core1==1&&Core2==1&&time==p2t+prevTime&&time==p1t+prevTime){
                    pBuf[c++]=p1;pBuf[c++]=th1c;pBuf[c++]=p2;pBuf[c++]=th2c;pBuf[c++]=time;
                    Core1=0; Core2=0;
                }
                else if(Core1==1&&Core2==1&&time==p2t+prevTime&&time!=p1t+prevTime){
                   pBuf[c++]=p1;pBuf[c++]=th1c;pBuf[c++]=p2;pBuf[c++]=th2c;pBuf[c++]=time;
                   Core2=0;
                   
                }
                else if(Core1==1&&Core2==1&&time!=p2t+prevTime&&time==p1t+prevTime){
                   pBuf[c++]=p1;pBuf[c++]=th1c;pBuf[c++]=p2;pBuf[c++]=th2c;pBuf[c++]=time;
                   Core1=0;
                   
                }
                
                    
                }
                e=0;
                
            }
        }
        if(Core2!=0){pBuf[c++]=0;pBuf[c++]=p2;pBuf[c++]=th2c;pBuf[c++]=prevTime+p2t;}
         if(Core1!=0){pBuf[c++]=p1;pBuf[c++]=th1c;pBuf[c++]=0;pBuf[c++]=prevTime+p1t;}
       
        
        //converting integers to characters
       int i=0;
       int c1=0;
       strcpy(readBuf,"");
       while(i<strC1.length()){readBuf[c1++]=strC1[i];i++;}
       readBuf[c1++]='\t';i=0;
       while(i<strC2.length()){readBuf[c1++]=strC2[i];i++;}
       readBuf[c1++]='\t';i=0;
       while(i<tstr.length()){readBuf[c1++]=tstr[i];i++;}
       readBuf[c1++]='\n';
       i=0;
       //copying into a character buffer to write output to a file
       while(i<c){
           string ss;int j =0;
           if(pBuf[i]==0){int j=0; while(j<str.length()){readBuf[c1++]=str[j];j++;}
           readBuf[c1++]='\t';readBuf[c1++]='\t';}
           else{
           ss = inToString(pBuf[i]);
           while(j<ss.length()){readBuf[c1++]=ss[j];j++;}
           ss.clear();j=0;
           readBuf[c1++]='.';
           ss = inToString(pBuf[i+1]);
           readBuf[c1++]=ss[0];
           readBuf[c1++]='\t';
           }
           if(pBuf[i]==0){
               if(pBuf[i+1]==0){
                   int j=0; while(j<str.length()){readBuf[c1++]=str[j];j++;}
                   readBuf[c1++]='\t';readBuf[c1++]='\t';j=0;
                   ss = inToString(pBuf[i+2]);
                   while(j<ss.length()){readBuf[c1++]=ss[j];j++;}
                   readBuf[c1++]='\n';ss.clear();j=0;
                   i=i+3;
               }
               else{
                    ss=inToString(pBuf[i+1]);
                    while(j<ss.length()){readBuf[c1++]=ss[j];j++;}
                    ss.clear();j=0;readBuf[c1++]='.';
                    ss = inToString(pBuf[i+2]);
                    readBuf[c1++]=ss[0];
                    readBuf[c1++]='\t';readBuf[c1++]='\t'; j=0;
                    ss = inToString(pBuf[i+3]);
                    while(j<ss.length()){readBuf[c1++]=ss[j];j++;}
                    readBuf[c1++]='\n';ss.clear();i=i+4;
                   }
              }else{
                   if(pBuf[i+2]==0){int j=0; while(j<str.length()){readBuf[c1++]=str[j];j++;}
                   readBuf[c1++]='\t';readBuf[c1++]='\t';j=0;
                   ss = inToString(pBuf[i+3]);
                   while(j<ss.length()){readBuf[c1++]=ss[j];j++;}
                   readBuf[c1++]='\n';ss.clear();j=0;i=i+4;
                   }
                   else{
                        ss=inToString(pBuf[i+2]);
                        while(j<ss.length()){readBuf[c1++]=ss[j];j++;}
                        ss.clear();j=0;readBuf[c1++]='.';
                        ss = inToString(pBuf[i+3]);
                        readBuf[c1++]=ss[0];ss.clear();readBuf[c1++]='\t';readBuf[c1++]='\t';
                        ss = inToString(pBuf[i+4]);j=0;
                        while(j<ss.length()){readBuf[c1++]=ss[j];j++;}
                         readBuf[c1++]='\n';j=0;i=i+5;
                       }
                 }
           
           
            
       } 
       
 size_t len= strlen(readBuf);
 outfile.write(readBuf,len);
 infile.close();     
 outfile.close(); 
 delete[]readBuf;delete[]pBuf;delete[]temp;delete[]AT;
 delete[]Dlines;delete[]ExeT;delete[]Th;delete[]Slines;
 delete[]Elines;delete[]proc;
return 0;
}
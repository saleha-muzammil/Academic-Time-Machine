/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package l164194;
import java.util.Scanner;
import java.util.ArrayList;

/**
 *
 * @author l164194
 */
public class L164194 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ArrayList<patient> a=new ArrayList<patient>();
        int k=0;
        System.out.println("press 1 to register patients");
        System.out.println("press 2 to maintain numbe of staff members");
        System.out.println("press 3 quit");
        Scanner input=new Scanner(System.in);
        k=input.nextInt();
        
        while (k==1)
        {
            
                 System.out.println("enter name");
                 String name;
                 name=input.next();
                 int age;
                 System.out.println("enter age");
                 age=input.nextInt();
                 String d;
                 String dat;
                  int i;
                 System.out.println("enter department");
                 d=input.next();
                  System.out.println("enter date");
                  dat=input.next();
                  // System.out.println("enter nymber of times the patient comes consectively");
                  // i=input.nextInt();
                   System.out.println("enter ward_numbery");
                   int w=input.nextInt();
                    int l=0;
                   for(person pat:a)
                   {
                       if(pat.getName()==name)
                       {
                           l++;
                       }
                   }
                   departments dep=new departments(d);
                   
                   patient p=new patient(name,age,w,dep,dat,l);
                   a.add(p);
                  
                   System.out.println("press 1 to register patients");
                    System.out.println("press 2 to maintain numbe of staff members");
                    System.out.println("press 3 quit");
                     k=input.nextInt();
  
        }
        
        if(k==2)
        {
            
        }
        
        else if(k==3)
        {
          
        }
        
    }
    
}

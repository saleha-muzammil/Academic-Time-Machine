
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q1;

import java.util.Scanner;
import java.util.ArrayList;


/**
 *
 * @author l183114
 */
public class Q1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int x=1;
        ArrayList<student> students=new ArrayList<student>(500);
          Scanner waqas=new Scanner(System.in);
        String name;
        String cnic;
        String address;
     String visa;
              String type=null;
        System.out.println("enter 1 to continue and 2 to exit");
        x=waqas.nextInt();
        while (x==1)
        {
              companies c=new australiavisacompany();
            System.out.println("enter name of student");
          
            name=waqas.next();
             System.out.println("enter CNIC of student");
             cnic=waqas.next();
               System.out.println("enter address of student");
               address=waqas.next();
               System.out.println("enter country where you want to go in small letters :: australia , usa , brazil , spain , canada");
               visa=waqas.next();
               if(visa.equals("australia"))
               {
                    System.out.println("enter type of visa in small letters :: immigration  tourist  visinting urgent research");
                     type=waqas.next();
                     if(type.equals("visiting"))
                     {
                          visiting v=c.V();
                     }
                     else if (type.equals("research"))
                     {
                         research v=c.R();
                     }
                      else if (type.equals("immigration"))
                     {
                          imigration v=c.I();
                     }
                      else if (type.equals("urgent"))
                     {
                          urgent v=c.U();
                     }
                      else if (type.equals("tourist"))
                     {
                          tourist v=c.T();
                     }
               }
               else if(visa.equals("usa"))
               {
                    System.out.println("enter type of visa in small letters :: immigration  tourist  visinting urgent research");
                    type=waqas.next();
                      if(type.equals("visiting"))
                     {
                          visiting v=c.V();
                     }
                     else if (type.equals("research"))
                     {
                         research v=c.R();
                     }
                      else if (type.equals("immigration"))
                     {
                          imigration v=c.I();
                     }
                      else if (type.equals("urgent"))
                     {
                          urgent v=c.U();
                     }
                      else if (type.equals("tourist"))
                     {
                          tourist v=c.T();
                     }
               }
               else if(visa.equals("canada"))
               {
                    System.out.println("enter type of visa in small letters :: immigration  tourist  visinting urgent research");
                     type=waqas.next();
                       if(type.equals("visiting"))
                     {
                          visiting v=c.V();
                     }
                     else if (type.equals("research"))
                     {
                         research v=c.R();
                     }
                      else if (type.equals("immigration"))
                     {
                          imigration v=c.I();
                     }
                      else if (type.equals("urgent"))
                     {
                          urgent v=c.U();
                     }
                      else if (type.equals("tourist"))
                     {
                          tourist v=c.T();
                     }
               }
               else if(visa.equals("spain"))
               {
                    System.out.println("enter type of visa in small letters :: immigration  tourist  visinting urgent research");
                     type=waqas.next();
                       if(type.equals("visiting"))
                     {
                          visiting v=c.V();
                     }
                     else if (type.equals("research"))
                     {
                         research v=c.R();
                     }
                      else if (type.equals("immigration"))
                     {
                          imigration v=c.I();
                     }
                      else if (type.equals("urgent"))
                     {
                          urgent v=c.U();
                     }
                      else if (type.equals("tourist"))
                     {
                          tourist v=c.T();
                     }
               }
               else if(visa.equals("brazil"))
               {
                    System.out.println("enter type of visa in small letters :: immigration  tourist  visinting urgent research");
                     type=waqas.next();
                       if(type.equals("visiting"))
                     {
                          visiting v=c.V();
                     }
                     else if (type.equals("research"))
                     {
                         research v=c.R();
                     }
                      else if (type.equals("immigration"))
                     {
                          imigration v=c.I();
                     }
                      else if (type.equals("urgent"))
                     {
                          urgent v=c.U();
                     }
                      else if (type.equals("tourist"))
                     {
                          tourist v=c.T();
                     }
               }
                
               student s=new student(name,cnic,address,type);
           students.add(s);
        }
       
        for (int i=0;i<students.size();i++)
        {
             System.out.println("name of student is " + students.get(i).getName() + " and cnic is " +  students.get(i).getCnic() + " and address is " +  students.get(i).getAddress() );
        }
        
        
        
        // TODO code application logic here
    }
    
}

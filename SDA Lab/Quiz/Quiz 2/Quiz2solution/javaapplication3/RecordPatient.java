/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication3;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author asad.ullah
 */
public class RecordPatient {
   List<Patient> Patients= new ArrayList<Patient>();
   void AddPatient(Patient a)
   {
        
      Patients.add(a);    
   }
    
   
     void  DeletePatient(Patient a)
   {
  
           Patients.remove(a);
       
       
   }
     
       boolean SearchPatient(Patient a)
   {
      
       for(Patient b: Patients)
       {
          if(a.cnic==b.cnic) {
               return true;
           }
      
       }
        return false;
}
       
}

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication3;

/**
 *
 * @author asad.ullah
 */
public class JavaApplication3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Patient a =new Patient("zahid", 234,45);
         Patient b =new Patient("zahid1", 23434,45);
        RecordPatient p =new RecordPatient();
        p.AddPatient(a);
        p.DeletePatient(b);
        p.SearchPatient(b);
        
    }
}

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package l164281;
import java.util.List;
import java.util.ArrayList;
/**
 *
 * @author l164718
 */
public class L164281 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        faculty f;
        Lecturer l1=new Lecturer("Hammad", "1", 500000, "10-3-08", "10-3-38");
        Professor p=new Professor("Fakhar", "2", 50000, "10-3-08", "10-3-38");
        VisitingLecturer v=new VisitingLecturer("Badar", "3", 50, "10-3-08", "10-3-38");
        f=l1;
        f.CalculateTax();
        f.facultyInfo();
                f=p;
        f.CalculateTax();
        f.facultyInfo();
                f=v;
        f.CalculateTax();
        f.facultyInfo();

        
    }
}

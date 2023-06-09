/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package l164281;

/**
 *
 * @author l164718
 */
public class Professor extends ParmanentFaculty {

    public Professor(String Name, String CNIC, int Salary, String DateOfJoin, String DateOfResign) {
        super(Name, CNIC, Salary, DateOfJoin, DateOfResign);
    }
    void CalculateTax()
    {
        System.out.println(0.03*Salary);
    }
    void facultyInfo()
    {
                System.out.println("Name "+Name);
        System.out.println("CNIC "+CNIC);
        System.out.println("Salary "+(Salary-(0.03*Salary)));
        System.out.println("DateOfJoin "+DateOfJoin);
        System.out.println("DateOfResign "+DateOfResign);
    }
    
}

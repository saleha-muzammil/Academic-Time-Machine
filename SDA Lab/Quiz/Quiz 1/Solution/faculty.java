/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package l164281;

/**
 *
 * @author l164718
 */
abstract public class faculty {
    protected String Name;
    protected String CNIC;
    protected int Salary;
    faculty(String Name,String CNIC,int Salary)
    {
        this.Name=Name;
        this.CNIC=CNIC;
        this.Salary=Salary;
    }
    abstract void CalculateTax();
    abstract void facultyInfo();
}

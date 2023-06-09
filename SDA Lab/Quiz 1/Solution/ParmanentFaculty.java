/*/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package l164281;

/**
 *
 * @author l164718
 */
abstract public class ParmanentFaculty extends faculty {
    protected String DateOfJoin;
    protected String DateOfResign;

    ParmanentFaculty(String Name,String CNIC,int Salary,String DateOfJoin, String DateOfResign) {
        super(Name,CNIC,Salary);
        this.DateOfJoin = DateOfJoin;
        this.DateOfResign = DateOfResign;
    }
   abstract void CalculateTax();
    abstract void facultyInfo();
}

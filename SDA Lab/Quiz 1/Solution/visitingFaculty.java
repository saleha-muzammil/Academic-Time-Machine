/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package l164281;

/**
 *
 * @author l164718
 */
abstract public class visitingFaculty extends faculty{
    protected String ContractDate;
    protected String PaymentDeliveryDate;
    visitingFaculty(String Name,String CNIC,int Salary,String ContractDate,String PaymentDeliveryDate)
    {
        super(Name,CNIC,Salary);
        this.ContractDate=ContractDate;
        this.PaymentDeliveryDate=PaymentDeliveryDate;
    }
    abstract void CalculateTax();
    abstract void facultyInfo();
}

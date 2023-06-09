/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package l164281;

/**
 *
 * @author l164718
 */
public class VisitingLecturer extends visitingFaculty{
    VisitingLecturer(String Name,String CNIC,int Salary,String ContractDate,String PaymentDeliveryDate)
    {
        super(Name,CNIC,Salary,ContractDate,PaymentDeliveryDate);
    }
    void CalculateTax()
    {
        System.out.println(0.17*Salary);
    }
    void facultyInfo()
    {
        System.out.println("Name "+Name);
        System.out.println("CNIC "+CNIC);
        System.out.println("Salary "+(Salary-(0.17*Salary)));
        System.out.println("ContractDate "+ContractDate);
        System.out.println("PaymentDeliveryDate "+PaymentDeliveryDate);
        
    }
}

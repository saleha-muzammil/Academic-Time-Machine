    /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab.mid;

/**
 *
 * @author l154216
 */
public class StudentLoan {
    String rollNumber;
    int loan;
    boolean isFineDue;

    public StudentLoan(String rollNumber, int loan, boolean isFineDue) {
        this.rollNumber = rollNumber;
        this.loan = loan;
        this.isFineDue = isFineDue;
    }
    
}

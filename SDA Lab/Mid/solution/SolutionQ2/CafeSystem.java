/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab.mid;

import java.util.ArrayList;

/**
 *
 * @author l154216
 */
public class CafeSystem {
    int noofSalesperday,noofpurchasesperDay;
    int saleperDay,purchaseperDay;
   ArrayList<StudentLoan > a;

    public CafeSystem() {
     this.noofSalesperday=this.noofpurchasesperDay=this.purchaseperDay=this.purchaseperDay=0;
      this.a = new ArrayList<StudentLoan>(10);
     
    }

    public int getPurchaseperDay() {
        return purchaseperDay;
    }

    public int getSaleperDay() {
        return saleperDay;
    }
    void foodPurchased(Student s,Food f)
    {
            
      s.foodPurchased=f;
      this.noofSalesperday=this.noofSalesperday+1;
      this.saleperDay=this.saleperDay+f.price;
    
    }
    void foodonLoan(Student s,Food f)
    {
       //  Student Loan s=new Stude
       //a.add(s.rollNo,f.price,false);
    
    
    }
    void fineStudent(Student s)
    {
    
      s.fine=s.pendingSum*10;
      s.fine=s.fine/100;
    
    }
    
    
}

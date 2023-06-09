/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package l164194;

/**
 *
 * @author l164194
 */
public class staff extends person{
    
    private departments d;
    private int pay;

    public staff() {
    }

    public departments getD() {
        return d;
    }

    public int getPay() {
        return pay;
    }

    public void setD(departments d) {
        this.d = d;
    }

    public void setPay(int pay) {
        this.pay = pay;
    }
    
    staff(String name,int age,int pay,departments d)
    {
        super(name,age);
        this.d=d;
        this.pay=pay;
        
    }
    
}

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
public class patient extends person {
    
    private departments d;
    private int ward_number;
    private String date_arrival;
    private Boolean waiting;
    private Boolean premium;
    private int i;

    public departments getD() {
        return d;
    }

    public int getWard_number() {
        return ward_number;
    }

    public String getDate_arrival() {
        return date_arrival;
    }

    public Boolean getWaiting() {
        return waiting;
    }

    public Boolean getPremium() {
        return premium;
    }

    public int getI() {
        return i;
    }

    public void setD(departments d) {
        this.d = d;
    }

    public void setWard_number(int ward_number) {
        this.ward_number = ward_number;
    }

    public void setDate_arrival(String date_arrival) {
        this.date_arrival = date_arrival;
    }

    public void setWaiting(Boolean waiting) {
        this.waiting = waiting;
    }

    public void setPremium(Boolean premium) {
        this.premium = premium;
    }

    public void setI(int i) {
        this.i = i;
    }
    
    patient()
    {
        
    }
    patient(String name,int age,int ward_number,departments d,String date,int i)
    {
        super(name,age);
        this.d=d;
        this.ward_number=ward_number;
        this.date_arrival=date;   
        this.i=i;
    }
    
    public void status()
    {
        if (i==1)
            this.waiting=true;
        else if (i==3)
            this.premium =true;     
    }
    public String N(patient p)
    {
        return p.getName();
    }
}

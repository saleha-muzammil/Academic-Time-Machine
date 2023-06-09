/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q1;

/**
 *
 * @author l183114
 */
public class student {
    private String name;
    private String cnic;
    private String address;
    private String visa;

    public void setVisa(String visa) {
        this.visa = visa;
    }

    public String getVisa() {
        return visa;
    }
    
   public student(String name,String cnic,String address,String visa)
   {
       this.name=name;
       this.cnic=cnic;
       this.address=address;
       this.visa=visa;
   }

    public String getName() {
        return name;
    }

    public String getCnic() {
        return cnic;
    }

    public String getAddress() {
        return address;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCnic(String cnic) {
        this.cnic = cnic;
    }

    public void setAddress(String address) {
        this.address = address;
    }
   
}

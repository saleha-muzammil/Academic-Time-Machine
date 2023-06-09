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
public class administrative_staff extends staff{
    
     private String type;
   
    private int i;

    public String getType() {
        return type;
    }

    public int getI() {
        return i;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setI(int i) {
        this.i = i;
    }
    administrative_staff(String name,int age,int pay,departments d)
    {
       super(name,age,pay,d);
       type="administrative_staff";
    }
    
}

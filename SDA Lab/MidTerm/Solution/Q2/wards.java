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
public class wards {

  
    
    private String name;
    private waiting_area waiting_area_name;
      public wards() {
    }

    public String getName() {
        return name;
    }

    public waiting_area getWaiting_area_name() {
        return waiting_area_name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setWaiting_area_name(waiting_area waiting_area_name) {
        this.waiting_area_name = waiting_area_name;
    }
      
    wards(String name,waiting_area waiting_area_name)
    {
        this.name=name;   
        waiting_area_name=this.waiting_area_name;
    }
}

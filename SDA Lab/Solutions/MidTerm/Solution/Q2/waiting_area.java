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
public class waiting_area {
     private String name;
    private wards ward_name;

    public waiting_area() {
    }

    public String getName() {
        return name;
    }

    public wards getWard_name() {
        return ward_name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setWard_name(wards ward_name) {
        this.ward_name = ward_name;
    }
    
    waiting_area(String name,wards ward_name)
    {
        this.name=name;   
        ward_name=this.ward_name;
    }
}

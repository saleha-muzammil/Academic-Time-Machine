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
public class surgical_department extends departments {
    private String type;

    public void setType(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public surgical_department() {
    }
    surgical_department(String name,String type)
    {
        super(name);
        this.type=type;
           wards w[]=new wards[10]; 
    }
    
}

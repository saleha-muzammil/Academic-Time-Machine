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
public class hospital {
    private String name;

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public hospital() {
    }
    hospital(String name)
    {
        this.name=name;
        departments d[]=new departments[10];
    }
    
}

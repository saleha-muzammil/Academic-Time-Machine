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
public class departments {
    private String name;
    private staff s[];

    public departments() {
    }

    public String getName() {
        return name;
    }

    public staff[] getS() {
        return s;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setS(staff[] s) {
        this.s = s;
    }
    
    departments(String name)
    {
        this.name=name;
        s=new staff[100];
    }
}

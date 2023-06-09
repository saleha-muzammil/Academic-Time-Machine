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
public class person {
    
    private String name;

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
    
    private int age;

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public person() {
    }
  
    person(String name,int age)
    {
        this.name=name;
        this.age=age;
    }
    
}


package pkgfinal;

abstract public class Employee 
{
    int id;
    String name;
    int age;
    int salary;        
    String Type;

    public Employee(int id, String name, int age, int salary, String Type) 
    {
        this.id = id;
        this.name = name;
        this.age = age;
        this.salary = salary;
        this.Type = Type;
    }
    
    abstract int FindSalary();     
    
    abstract int getID();
    
    abstract public void Add(Employee e);
    
    abstract public void Remove(int id, String category);
    
}

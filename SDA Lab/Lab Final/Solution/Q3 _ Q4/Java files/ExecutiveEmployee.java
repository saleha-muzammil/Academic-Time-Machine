
package pkgfinal;

public class ExecutiveEmployee extends Employee
{
    static int count = 1;
    
    int id;
    String name;
    int age;
    int salary;
    String Type;

    public ExecutiveEmployee(String name, int age, int salary, String Type) 
    {
        super(count, name, age, salary, Type);
        count++;
    }

    @Override
    int FindSalary() 
    {
        return salary;
    }
    
    @Override
    int getID() 
    {
        return super.id;
    }

    @Override
    public void Add(Employee e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void Remove(int id , String category) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}

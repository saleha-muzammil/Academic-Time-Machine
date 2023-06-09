
package pkgfinal;

import java.util.ArrayList;
import java.util.List;


public class CEO extends Employee
{
    List<Employee> emps = new ArrayList<>();

    public CEO(int id, String name, int age, int salary, String Type) 
    {
        super(id, name, age, salary, Type);
    }
    
    @Override
    int FindSalary() 
    {
        return super.salary; 
    }        
    
    @Override
    public  void Add(Employee e)
    {
        this.emps.add(e);
    }
    
    @Override
    public void Remove(int id, String category)
    {
        if(category.equals("exe"))
        {

            for (int i = 0; i < this.emps.size(); i++) {
                if (this.emps.get(i).getID() == id && (this.emps.get(i) instanceof ExecutiveEmployee)) {
                    this.emps.remove(i);
                }
            }
        }
        
        else if(category.equals("off"))
        {
             for(int i = 0; i < this.emps.size(); i++)
            {
                if(this.emps.get(i).getID()==id && (this.emps.get(i) instanceof OfficersEmployee))
                {
                    this.emps.remove(i);
                }
             }
        }
        
         else if(category.equals("cler"))
        {
             for(int i = 0; i < this.emps.size(); i++)
            {
                if(this.emps.get(i).getID()==id && (this.emps.get(i) instanceof ClericalEmployee))
                {
                    this.emps.remove(i);
                }
             }
        }
    }

    @Override
    int getID() 
    {
        return super.id;
    }
}

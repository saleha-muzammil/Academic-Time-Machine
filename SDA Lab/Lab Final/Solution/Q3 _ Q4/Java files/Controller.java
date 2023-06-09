
package pkgfinal;

public class Controller 
{
    Controller cont;
    static Controller obj = null;
    
    DDBM accounting = new Accounting();
    DDBM hr = new HR();
    DDBM sales = new Sales();
    
    static
    {
        obj = new Controller();
    }
    
    private Controller() 
    {
        
    }
    
    public static Controller getInstance()
    {
        return obj;
    } 
    
    public void LogRequest(String dep)
    {
        boolean flag = false;
        
        if(dep.equalsIgnoreCase("Accounting"))
        {
            if(this.hr.getCurrentState() instanceof Operational)
            {
                this.hr.setCurrentState(new NonOperational());
                flag = true;
            }
            
            if(this.sales.getCurrentState() instanceof Operational)
            {
                flag = true;
                this.sales.setCurrentState(new NonOperational());
            }
            
            if(flag)
            {
                this.accounting.setCurrentState(new Operational());
                System.out.println("Accounting : Non-Operational : Operational");
            }
            
            else if(!flag && this.accounting.getCurrentState() instanceof Operational)
            {
                System.out.println("Accounting : Operational : Operational");
            }
            
            else if (!flag && !(this.accounting.getCurrentState() instanceof Operational))
            {
                System.out.println("Accounting : Operational ");
                
                this.accounting.LogInfo();
            }
        }
        
        else if(dep.equalsIgnoreCase("HR"))
        {
            if(this.accounting.getCurrentState() instanceof Operational)
            {
                this.accounting.setCurrentState(new NonOperational());
                flag = true;
            }
            
            if(this.sales.getCurrentState() instanceof Operational)
            {
                flag = true;
                this.sales.setCurrentState(new NonOperational());
            }
            
            if(flag)
            {
                this.hr.setCurrentState(new Operational());
                System.out.println("Accounting : Non-Operational : Operational");
            }
            
            else if(!flag && this.hr.getCurrentState() instanceof Operational)
            {
                System.out.println("Accounting : Operational : Operational");
            }
            
            else if (!flag && !(this.hr.getCurrentState() instanceof Operational))
            {
                System.out.println("Accounting : Operational ");
                
                this.accounting.LogInfo();
            }
            
        }
        
        else if(dep.equalsIgnoreCase("Sales"))
        {
             if(this.accounting.getCurrentState() instanceof Operational)
            {
                this.accounting.setCurrentState(new NonOperational());
                flag = true;
            }
            
            if(this.hr.getCurrentState() instanceof Operational)
            {
                flag = true;
                this.hr.setCurrentState(new NonOperational());
            }
            
            if(flag)
            {
                this.sales.setCurrentState(new Operational());
                System.out.println("Accounting : Non-Operational : Operational");
            }
            
            else if(!flag && this.sales.getCurrentState() instanceof Operational)
            {
                System.out.println("Accounting : Operational : Operational");
            }
            
            else if (!flag && !(this.sales.getCurrentState() instanceof Operational))
            {
                System.out.println("Accounting : Operational ");
                
                this.accounting.LogInfo();
            }
            
        }        
    }
        
    
}

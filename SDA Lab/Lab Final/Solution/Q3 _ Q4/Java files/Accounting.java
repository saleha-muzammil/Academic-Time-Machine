
package pkgfinal;

import java.util.ArrayList;
import java.util.List;


public class Accounting extends DDBM
{
    List<String> AllPreviousLogs;
    State currentState;
    State previousState;

    public Accounting() 
    {
        this.AllPreviousLogs = new ArrayList();
        this.currentState = new NonOperational();
    }
    
    public void ChangeState()
    {
        this.previousState = this.currentState;
        this.currentState.ChangeState(this);
    }
    

    @Override
    public void setCurrentState(State currentState) 
    {
        this.currentState = currentState;
    }   

    @Override
    public void LogInfo() 
    {
        System.out.println("Accounting Log :" );
        System.out.println("Previous State : " + this.previousState);
        System.out.println("Current State : " + this.currentState);
        
        String tmp = "Previous State : " + this.previousState + " , " + "Current State : " + this.currentState + "\n";
        
        this.AllPreviousLogs.add(tmp);
        
        System.out.println("All Previous Logs : ");
        
        for(int i = 0; i < this.AllPreviousLogs.size(); i++)
        {
            System.out.println(this.AllPreviousLogs.get(i));
        }
    }

    @Override
    public State getCurrentState() 
    {
        return currentState;
    }

    @Override
    public State getPreviousState() 
    {
        return previousState;
    }
    
    
    
}


package pkgfinal;


public abstract class DDBM 
{
    abstract public void setCurrentState(State currentState);
    
    abstract public void LogInfo();
    
    abstract public State getCurrentState() ;
    
    abstract public State getPreviousState() ;
}

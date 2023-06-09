package ta;

import java.io.File;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;

import ga.Chromosome;
import ga.GeneticAlgorithm;

public class TaskAssignmentMain {

    private GeneticAlgorithm gaObj;
    private Chromosome bestChromosome;/*best chromosome found*/
    private int generation;/* current generation */
    private Random random;
    private DataReader dataReaderObj;
    private ProblemData problemDataObj;
    
    /* bools to control behavior of GA */
    private boolean crossoverBool = true;
    private boolean mutationBool = true;
    private double startTime=0;
    private double endTime=0;
    double bestChromosomeFoundTime=0;
    
    public TaskAssignmentMain(String dataFilePath, int problemNumber){
    	dataReaderObj = new DataReader();
    	//Read the file and  get required ProblemData object, 
    	//Debug: you can insert a breakpoint after executing these two lines of code 
    	//and inspect the "problemDataObj" object to get the idea about the structure of the read data
    	
    	DataReader.readFile(new File(dataFilePath));
    	problemDataObj = (ProblemData)DataReader.problemList.get(problemNumber-1);
    	
    	
        random = new Random();
    	

  	  gaObj = new GeneticAlgorithm(problemDataObj.getJobsCount(), 
    		  problemDataObj.getAgentsCount(), Constants.POPULATION_SIZE, true, true);
    	startTime = System.currentTimeMillis();
    	//create initial population
    	//gaObj.initPopulation();
    	
    	//evaluate population
    	//gaObj.evaluatePopulation(problemDataObj);
    	
    	
    	//do{
    		//Crossover constructor to create child
    		
    		
    		// apply mutatation
    
    		
    		//evaluate child
    		
    		//maitain best chrososome
    		
    		
    	//}while(noImprovementIter<Constants.ITERATIONS_COUNT);
    	
    	    	
    	
    }
        
	
	public static void main(String args[]){
		
		System.out.println("Start of Imp: ");
		
        //start implementation here
		
		//System.out.println("Problem  agents  jobs             Best soln in each of the 10 trials                      Best Soln   Avg of Best Solns  Avg Best Soln Time   Avg Exec Time");
	
			
			//problemNumber = p+1;
			
			//for(int i=0;i<numberOfRuns;i++)
			    //create taskassignment object
			    
			    //get and print all the required fields
					  
			
		   //}
	
		
	}

}

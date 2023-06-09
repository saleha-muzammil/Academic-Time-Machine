/* GeneticAlgorithm.java
 * J Scott Cameron
 * 
 * This class controls a population of Genotypes 
 * for regenration using a Genetic Algorithm
 *
 * It uses the Java Reflection API so that
 * it is possible to change the fitness function
 * for new GA problems without having to touch this 
 * class
 */
package ga; 
import java.lang.reflect.*;
import java.util.*;
import java.io.*;

import ta.ProblemData;

public class GeneticAlgorithm{
    
    private Chromosome population[];/* population of Chromosome */
    private boolean crossover; /* boolean that control crossover */
    private boolean mutation; /* boolean that controls mutation */
    private int populationSize; /* population size */
    private int jobsCount; /* Number of jobs = length of Chromosome */
    private int agentsCount; /* Number of agents */
    private Random random; /* random object to be passed to genotypes */
    private int sumFitness; /* sum of all the fitnesses in the population */
    private int lowestFitness; /* the worst fitness found */
    private ArrayList<String> allChromosomesList = new ArrayList<String>();

    

    public GeneticAlgorithm()
    {
        
    }
    

    public GeneticAlgorithm(int jobsCount, int agentsCount, int popSize, 
                            boolean crossover, boolean mutation)
    {
        this.jobsCount = jobsCount;
        this.agentsCount = agentsCount;
        this.populationSize = popSize;
        this.crossover = crossover;
        this.mutation = mutation;
    }
    
    /* initializes the population with random Genotypes */
    public void initPopulation()
    {
        random = new Random();
        population = new Chromosome[populationSize];

        //initialize population of chromosomes
        //also take care of that no duplicated are allowed
    }
    
   
    
    
    public Chromosome TournamentSelection()
    {
       //implemenantation for a Tournament selection, 
    //return one selected parent 

      return null;
    }
    
    /* evaluates all the Chromosomes in the population and sorts them*/
    public void evaluatePopulation(ProblemData problemDataObj)
    {
        
        // evaluate all solutions in the population, (calculate fitness and unfitness values) 
        // you can iterate the population
    	//and can call evaluateChromosome(problemDataObj, chromsome) for each chromosome
    	
        /* sort the population */
        //Arrays.sort(population,new ChromosomeComparator());
    }
    
    public Chromosome evaluateChromosome(ProblemData problemDataObj,
    		Chromosome childChromosome)
    {
        
        //This method is used to evaluate one chromosome
                
     
            			
            			
        //apply problem specific heuristic, call applyProblemSpecificHeuristics()    			
            	
       

        /* sort the population */
        //Arrays.sort(population,new ChromosomeComparator());
        return childChromosome;
    }
    
    public void applyProblemSpecificHeuristics(Chromosome childChromosome,
    		int[] agentsResourcesUsage, ArrayList arrResourceCapacity,
    		ArrayList arrJobAllocCost, ArrayList arrResourceConsumed,
    		HashMap<Integer, ArrayList<Integer>> mapAgentsAssignments
    		){
         //you can change the signature of the methods (parameter list etc) according to your own requirement   
    
    }
    public Chromosome doCrossover(){
    	//select two parents using two binary tournaments
    	Chromosome parent1 = null;
    	Chromosome parent2 = null;
    	
    	return  new Chromosome(parent1, parent2, random);

    }
    
    public void doMutation(Chromosome child){
    	//child.mutate();
    }

    /* returns a string wiith all the Bitsets printed out */
    public String toString()
    {
        StringWriter sw = new StringWriter();
        
        for(int i=0;i<populationSize;i++)
        {
            sw.write(population[i].toString());
            sw.write("\n");
            
        }
        return sw.toString();
    }
    
    /* returns the worst Chromosome of the current population */
    public Chromosome worst()
    {
        return population[0];
    }
    
    /* returns the best genotype of the current population */
    public Chromosome best()
    {
        return population[population.length-1];
    }
    

    
}

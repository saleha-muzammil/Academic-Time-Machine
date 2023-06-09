
/** Genotype.java
 *J Scott Cameron 
 *This class contains a bit-vector with the "genes"
 *and a rating to be determined by the fitness
 *function of the Genetic Algorithm.
 *  
 *Note: All the contructors take a Random as a parameter
 *because when creating a whole slew of Genetypes very quickly
 *if each Genotype creates its own Random object then there are a lot
 *of identical Random objects since they're all initialized using the
 *current time in milliseconds. It takes less than a millisecond to create
 *a Genotype so the Random objects are initialized with the same time.
 *This is very bad if you want a population of unique Genotypes.
 *By including a Random object in the constructor the Genetic Algorithm
 *sends all the Genotypes a reference to the same Random object. This way
 *each objects gets the object at a different point in its progression.
 */
package ga;
import java.io.*;
import java.util.*;

public class Chromosome
{
    private int genes[];
    private int fitnessValue;
    private int unfitnessValue;
    private int length;
    private Random random;
   
    
    public Chromosome()
    {
        random = new Random();
    }
    
    /* creates a Random chromosome */
    public Chromosome(int numberOfJobs, int numberOfAgents, Random r)
    {
      //implementation to create a random solution
    }
    

    
        /* Crossover Constructor
         */
    public Chromosome(Chromosome g1,Chromosome g2,Random r)
    {
        //implement code for crossover
        
    }
    
    /* mutates Chromosome*/
    public void mutate()
    {
        //implement code for mutation

    }

	/**
	 * @return the genes
	 */
	public int[] getGenes() {
		return genes;
	}

	/**
	 * @param genes the genes to set
	 */
	public void setGenes(int[] genes) {
		this.genes = genes;
	}

	/**
	 * @return the fitnessValue
	 */
	public int getFitnessValue() {
		return fitnessValue;
	}

	/**
	 * @param fitnessValue the fitnessValue to set
	 */
	public void setFitnessValue(int fitnessValue) {
		this.fitnessValue = fitnessValue;
	}

	/**
	 * @return the unfitnessValue
	 */
	public int getUnfitnessValue() {
		return unfitnessValue;
	}

	/**
	 * @param unfitnessValue the unfitnessValue to set
	 */
	public void setUnfitnessValue(int unfitnessValue) {
		this.unfitnessValue = unfitnessValue;
	}

	/**
	 * @return the length
	 */
	public int getLength() {
		return length;
	}

	/**
	 * @param length the length to set
	 */
	public void setLength(int length) {
		this.length = length;
	}
    
   
}

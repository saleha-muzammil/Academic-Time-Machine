/** GenotypeComparator.java
 *  J Scott Cameron
 *
 *  This class is used to compare two Genotype for sorting
 *  Using this class will actually cause reverse-sorting
 *  so that the best genotype is at the front of the Array
 */
package ga;
import java.util.*;
import java.io.*;

public class ChromosomeComparator implements Comparator
{
	public ChromosomeComparator()
    {
	
    }
    
    /* returns 1 if Chromosome 1 is smaller
     * -1 if Chromosome 1 is larger
     * and 0 if they are equal
     */
    public int compare(Object o1, Object o2)
    {
    	Chromosome g1 = (Chromosome)o1;
    	Chromosome g2 = (Chromosome)o2;
    	
    	if(g1.getUnfitnessValue() < g2.getUnfitnessValue())
        {
            return 1;
        }else if(g1.getUnfitnessValue() > g2.getUnfitnessValue())
        {
            return -1;
        }else if(g1.getFitnessValue() < g2.getFitnessValue())
        {
            return 1;
        }
        else if(g1.getFitnessValue() > g2.getFitnessValue())
        {
            return -1;
        }
        
        return 0;
    }
}

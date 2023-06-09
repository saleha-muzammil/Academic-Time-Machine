package ta;
import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author Irfan
 *
 */
public class DataReader {

	/**b
	 * @param args
	 */
	   static ArrayList<ProblemData> problemList = new ArrayList<ProblemData>();
	   
/*	public static void main(String[] args) {
		// TODO Auto-generated method stub
		readFile(new File("E://personals/problem-data/gap-data/gapa.txt"));
		printData();

	}*/
	
	public static void readFile(File fileName) {
	
	FileInputStream fis = null;
	BufferedInputStream bis = null;
	DataInputStream dis = null;
    String s;
    int lineCount =0;
    int numOfProblems = 0,problemsCount = 0;
    int numOfAgents = 0;
    int numOfJobs = 0;
    ArrayList<Integer> joblist = new ArrayList<Integer>();
    ArrayList<ArrayList<Integer>> JobAllocationCostList = new ArrayList<ArrayList<Integer>>();
    ArrayList<ArrayList<Integer>> ResourceConsumedList = new ArrayList<ArrayList<Integer>>();
    ArrayList<Integer> ResourceCapacityList = new ArrayList<Integer>();
    int numOfdataSets = 0;
    int count1 =0,count2 =0;
	try {
		fis = new FileInputStream(fileName);

 		bis = new BufferedInputStream(fis);
		dis = new DataInputStream(bis);
		
         while (dis.available() != 0) {
		    s = dis.readLine();
		  //  System.out.println(s);
		     String [] s2 = s.split(" ");
		     if(lineCount == 0)
		     {
		    	 numOfProblems = Integer.parseInt(s2[1]);
		    	 lineCount++;
		     }
		     else if(problemsCount <= numOfProblems)
		     {
		    	 if(numOfdataSets == 0)
		    	 {
		    		if(problemsCount >0)
		    		{
		    			ProblemData problemData = new ProblemData(problemsCount+1,numOfAgents,numOfJobs,
		    					JobAllocationCostList,ResourceConsumedList, ResourceCapacityList);
		    			problemList.add(problemData);
		    			JobAllocationCostList = new ArrayList<ArrayList<Integer>>();
		    			ResourceConsumedList = new ArrayList<ArrayList<Integer>>();
		    			ResourceCapacityList = new ArrayList<Integer>();
		    			joblist = new ArrayList<Integer>();
			    		count1 = 0;
			    		count2 = 0;

		    		}
		    		 
		    		 numOfAgents = Integer.parseInt(s2[1]);
		    		 numOfJobs = Integer.parseInt(s2[2]);
		    		 problemsCount++; 
		    		 numOfdataSets = 1;
		    	 }
		    	 else
		    	 {
		    			if(count1+s2.length-1 > numOfJobs)
		    			{
			    			if(numOfdataSets == 1)
			    				JobAllocationCostList.add(joblist);
			    			else if(numOfdataSets == 2)
			    				ResourceConsumedList.add(joblist);
			    			joblist = new ArrayList<Integer>();
			    			count1 = 0;
			    			count2 ++;
			    			if(count2 == numOfAgents)
			    			{
			    				numOfdataSets++;
			    				count2 = 0;
			    			}
		    			}
		    			if(numOfdataSets < 3)
		    			{
			    			for(int i=1;i<s2.length;i++)
				    			joblist.add(Integer.parseInt(s2[i]));
				    		count1+= s2.length-1;
		    			}
		    			else if(numOfdataSets == 3)
			    		{
			    		//	if(numOfAgents != s2.length-1)
			    			//	System.out.println("Data Format Error: Resource Capacity List Length does not match number of Agents");
			    		//	System.out.println(s);
			    			for(int i=1;i<s2.length;i++)
			    				ResourceCapacityList.add(Integer.parseInt(s2[i]));
			    			if(ResourceCapacityList.size() == numOfAgents)
			    				numOfdataSets = 0;
			    			
			    		}
		    	 }
		    	 
		     }
		 
         }
		ProblemData problemData = new ProblemData(problemsCount+1,numOfAgents,numOfJobs,
				JobAllocationCostList,ResourceConsumedList, ResourceCapacityList);
		problemList.add(problemData);

     fis.close();
     bis.close();
     dis.close();
	} catch (FileNotFoundException ex) {
        ex.printStackTrace();
    } catch (Exception ex) {
        ex.printStackTrace();
    }
	}
	
	static void printData()
	{
		System.out.println(problemList.size());
		for(int i=0;i<problemList.size();i++)
		{
			ProblemData d = (ProblemData)problemList.get(i);
			System.out.println(d.getAgentsCount()+" "+d.getJobsCount());
			
			for(int j=0;j<d.getJobAllocationCost().size();j++)
			{
				ArrayList<Integer> joblist = (ArrayList<Integer>)d.getJobAllocationCost().get(j);
				for(int k =0; k < joblist.size();k++)
				{
					System.out.print(joblist.get(k)+" ");
					if(k%12 == 0 && k >0)
						System.out.println();
				}
				System.out.println();
			}
			for(int j=0;j<d.getResourceConsumed().size();j++)
			{
				ArrayList<Integer> resourcelist = (ArrayList<Integer>)d.getResourceConsumed().get(j);
				for(int k =0; k < resourcelist.size();k++)
				{
					System.out.print(resourcelist.get(k)+" ");
					if(k%12 == 0 && k >0)
						System.out.println();
				}
				System.out.println();
			}
			for(int j =0; j < d.getResourceCapacity().size();j++)
			{
					System.out.print(d.getResourceCapacity().get(j)+" ");
					if(j%12 == 0 && j >0)
						System.out.println();
			}
			System.out.println();
						
		}
			
		
	}
	
}

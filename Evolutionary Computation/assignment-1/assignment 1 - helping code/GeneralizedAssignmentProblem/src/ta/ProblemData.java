package ta;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;


public class ProblemData {
	
	private int problemNumber;
	private int agentsCount;
	private int jobsCount;
	
	private ArrayList<ArrayList<Integer>> jobAllocationCostList = new ArrayList<ArrayList<Integer>>();
	private ArrayList<ArrayList<Integer>> resourceConsumedList = new ArrayList<ArrayList<Integer>>();
	private ArrayList<Integer> resourceCapacityList = new ArrayList<Integer>();
	
	ProblemData(int num, int agents, int jobs, ArrayList<ArrayList<Integer>> cost, ArrayList<ArrayList<Integer>> resource, ArrayList<Integer> capacity)
	{
		problemNumber = num;
		agentsCount = agents;
		jobsCount = jobs;
		jobAllocationCostList = cost;
		resourceConsumedList = resource;
		resourceCapacityList = capacity;
				
	}

	/**
	 * @return the problemNumber
	 */
	public int getProblemNumber() {
		return problemNumber;
	}

	/**
	 * @param problemNumber the problemNumber to set
	 */
	public void setProblemNumber(int problemNumber) {
		this.problemNumber = problemNumber;
	}

	/**
	 * @return the agentsCount
	 */
	public int getAgentsCount() {
		return agentsCount;
	}

	/**
	 * @param agentsCount the agentsCount to set
	 */
	public void setAgentsCount(int agentsCount) {
		this.agentsCount = agentsCount;
	}

	/**
	 * @return the jobsCount
	 */
	public int getJobsCount() {
		return jobsCount;
	}

	/**
	 * @param jobsCount the jobsCount to set
	 */
	public void setJobsCount(int jobsCount) {
		this.jobsCount = jobsCount;
	}

	/**
	 * @return the jobAllocationCostList
	 */
	public ArrayList<ArrayList<Integer>> getJobAllocationCost() {
		return jobAllocationCostList;
	}

	/**
	 * @param jobAllocationCostList the jobAllocationCostList to set
	 */
	public void setJobAllocationCost(ArrayList<ArrayList<Integer>> jobAllocationCostList) {
		this.jobAllocationCostList = jobAllocationCostList;
	}

	/**
	 * @return the resourceConsumedList
	 */
	public ArrayList<ArrayList<Integer>> getResourceConsumed() {
		return resourceConsumedList;
	}

	/**
	 * @param resourceConsumedList the resourceConsumedList to set
	 */
	public void setResourceConsumed(ArrayList<ArrayList<Integer>> resourceConsumedList) {
		this.resourceConsumedList = resourceConsumedList;
	}

	/**
	 * @return the resourceCapacityList
	 */
	public ArrayList<Integer> getResourceCapacity() {
		return resourceCapacityList;
	}

	/**
	 * @param resourceCapacityList the resourceCapacityList to set
	 */
	public void setResourceCapacity(ArrayList<Integer> resourceCapacityList) {
		this.resourceCapacityList = resourceCapacityList;
	}
	
	

}
